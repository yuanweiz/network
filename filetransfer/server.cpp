#include <cstdio>
#include <vector>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Callbacks.h>
//#include <muduo/net/TcpConnection.h>
#include "FileTransfer.pb.h"
#include "Dispatcher.h"
#include "Codec.h"
using namespace std;
using namespace muduo;

class FileTransferServer{
    public:
        using FilePtr = std::shared_ptr<FILE>;
        struct Context{
            FilePtr fp;
            bool running;
        };
        FileTransferServer (net::EventLoop* e, const net::InetAddress & addr)
            :server_(e, addr,"ChatServer")
        {
            //use lambda to capture this
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
        }

        //forward callbacks
        //currently empty
        void onConnection(const net::TcpConnectionPtr & ) {
            //send a request to trigger init
            //encoder_.sendInitRequest(conn);
        }
        

        void onMessage (const net::TcpConnectionPtr & ,
                net::Buffer*buf,
                Timestamp )
        {
            auto msg=codec_.retrieveMessage(buf);
            //dispatcher_.onMessage(msg.get());
        }

        void sendTrunkOrShutdown(const net::TcpConnectionPtr & conn){
            char buf[65536];
            const auto & pfile = boost::any_cast<const FilePtr&>(conn->getContext());
            size_t n = ::fread(buf,1,sizeof(buf),pfile.get());
            if (n==0){
                conn->shutdown();
            }
            else {
                Trunk trunk;
                trunk.set_data(buf,n);
                codec_.sendMessage(conn,&trunk);
                //conn->send(buf,n);
            }
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
