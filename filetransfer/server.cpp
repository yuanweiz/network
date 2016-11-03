#include <cstdio>
#include <vector>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Callbacks.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/base/Logging.h>
#include "FileTransfer.pb.h"
#include "Dispatcher.h"
#include "Codec.h"
#include "Context.h"
using namespace std;
using namespace muduo;

class FileTransferServer{
    public:
        //using FilePtr = std::unique_ptr<FILE,decltype(&::fclose)>;
        using FilePtr = std::shared_ptr<FILE>;
        using TcpConnectionPtr = muduo::net::TcpConnectionPtr;
        using Message = ::google::protobuf::Message;
        //using ConnectionList = std::vector<Connection>;
        FileTransferServer (net::EventLoop* e, const net::InetAddress & addr)
            :server_(e, addr,"FileTransferServer")
        {
            server_.setConnectionCallback(
                    [this](const net::TcpConnectionPtr & conn) {
                        this->onConnection(conn);
                    }
                    );
            server_.setMessageCallback(
                    [this](const net::TcpConnectionPtr & conn,
                        net::Buffer*buf,
                        Timestamp ts){
                    this->onMessage(conn,buf,ts);
            });
            server_.setWriteCompleteCallback(
                    [this](const net::TcpConnectionPtr & conn){
                    this->sendTrunkOrShutdown(conn);
                    }
                    );

            
            dispatcher_.registerCallback<Init>(
                    [=](const TcpConnectionPtr& conn,Init*msg)->void{
                    this->onInitMessage(conn,msg);
                    });

            dispatcher_.registerCallback<Pause>(
                    [=](const TcpConnectionPtr& conn,Pause*msg)->void{
                    this->onPauseMessage(conn,msg);
                    });

            dispatcher_.registerCallback<Resume>(
                    [=](const TcpConnectionPtr& conn,Resume*msg)->void{
                    this->onResumeMessage(conn,msg);
                    });
        }

        void onConnection(const net::TcpConnectionPtr & ) {
        }

        void onMessage (const net::TcpConnectionPtr & conn,
                net::Buffer*buf,
                Timestamp )
        {
            auto msg=codec_.retrieveMessage(buf);
            dispatcher_.onMessage(conn,msg.get());
        }

        void onWriteComplete(const net::TcpConnectionPtr & conn){
            const Context & ctx = boost::any_cast<const Context &>(conn->getContext());
            if (ctx.running){
                sendTrunkOrShutdown(conn);
            }
        }

        void sendTrunkOrShutdown(const net::TcpConnectionPtr & conn){
            static int total = 0;
            char buf[65536];
            const Context & ctx = boost::any_cast<const Context &>(conn->getContext());
            FILE* fp = ctx.fp.get();
            size_t n = ::fread(buf,1,ctx.trunkSize,fp);
            //don't handle n<trunkSize, leave it to next iteration
            if (n==0){
                conn->shutdown();
            }
            else {
                Trunk trunk;
                trunk.set_data(buf,n);
                codec_.sendMessage(conn,static_cast<Message*>(&trunk));
                total+=n;
                LOG_INFO << "send "<<n<<" bytes, total="<<total;
            }
        }

        void onInitMessage(const net::TcpConnectionPtr & conn, Init * init){
            std::string fname=init->filename();
            int trunkSize = init->trunksize();
            int startIdx = init->startidx();
            FILE * fp = ::fopen(fname.c_str(),"rb");
            ::fseek(fp,startIdx*trunkSize,SEEK_CUR);
            Context ctx(fp,trunkSize);
            conn->setContext( boost::any{std::move(ctx)});
            //send first trunk
            sendTrunkOrShutdown(conn);//this will indirectly trigger onWriteComplete
        }

        void onPauseMessage(const net::TcpConnectionPtr & conn, Pause * ){
            const Context & ctx = boost::any_cast<const Context &>(conn->getContext());
            ctx.running = false;
        }

        void onResumeMessage(const net::TcpConnectionPtr & conn, Resume * ){
            const Context & ctx = boost::any_cast<const Context &>(conn->getContext());
            ctx.running = true;
            //re-trigger 
            sendTrunkOrShutdown(conn);
        }

        void start(){
            server_.start();
        }
        
    private:
        void handlePause(Pause*){
        }
        void handleResume(Resume*){
        }
        net::TcpServer server_;
        Codec codec_;
        Dispatcher dispatcher_;
};

int main (){
    net::EventLoop e;
    net::InetAddress addr(8765); 
    FileTransferServer server(&e, addr);
    server.start();
    e.loop();
    return 0;
}
