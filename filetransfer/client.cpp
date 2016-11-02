#include <cstdio>
#include <vector>
#include <muduo/net/EventLoopThread.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpClient.h>
//#include <muduo/base/Condition.h>

#include "FileTransfer.pb.h"
#include "Dispatcher.h"
#include "Codec.h"
#include "Context.h"

using namespace std;
using namespace muduo;
using namespace std::placeholders;

//#include <muduo/net/Callbacks.h>
//#include <muduo/net/TcpConnection.h>

muduo::MutexLock mutex_;
muduo::Condition cond_(mutex_);
bool done=false;

class FileTransferClient{
    public:
        using FilePtr = shared_ptr<FILE> ;
        using TcpConnectionPtr = muduo::net::TcpConnectionPtr;
        FileTransferClient(net::EventLoop*loop,const net::InetAddress & addr)
            :client_(loop,addr,"FileTransferClient"),
            fp(fopen("file","ab"),::fclose)
        {
            client_.setMessageCallback(
                    [this](const net::TcpConnectionPtr & conn,
                        net::Buffer * buf,
                        Timestamp ts){
                    this->onMessage(conn,buf,ts);
                    }
                    );
            client_.setConnectionCallback( 
                    std::bind(&FileTransferClient::onConnection,this,
                        _1));
            dispatcher_.registerCallback<Trunk>(
                    std::bind(&FileTransferClient::handleTrunk,this,_1,_2));

        }
        void write (const char * buf,size_t size){
            client_.connection()->send(buf,size);
        }
        
        void connect(){
            client_.connect();
        }
        
    private:
        void handleTrunk(const TcpConnectionPtr & ,Trunk*trunk){
            auto str = trunk->data();
            fwrite(str.data(),1,str.size(),fp.get());
        }
        void onMessage(const net::TcpConnectionPtr & ,
                net::Buffer* buf,
                Timestamp ){
            auto msg =  codec_.retrieveMessage(buf);
            //Don't worry about null pointer, dispatcher
            //will handle it.
            //dispatcher_.onMessage(msg.get());
        }
        void onConnection(const net::TcpConnectionPtr & conn){
            if (conn->connected()){
                //currently just shutdown
                conn->shutdown();

                Init initMsg;
                initMsg.set_trunksize(512);
                initMsg.set_filename("file");
                initMsg.set_startidx(0);
                codec_.sendMessage(conn,&initMsg);
                conn->setContext(initMsg.filename());
            }
            else if (conn->disconnected()){
                MutexLockGuard guard(mutex_);
                done = true;
                cond_.notify();
            }
        }
        net::TcpClient client_;
        Codec codec_;
        //net::TcpConnectionPtr conn;
        Dispatcher dispatcher_;
        FilePtr fp;
};

int main (){
    //net::EventLoop e;
    net::EventLoopThread loopThread;
    net::InetAddress addr("127.0.0.1",8765);
    net::EventLoop * e=loopThread.startLoop();
    FileTransferClient client( e, addr);
    client.connect();
    
    {
        MutexLockGuard guard(mutex_);
        while (!done){
            cond_.wait();
        }
    }
    e->quit();
    e->runInLoop([](){fprintf(stderr,"Hello");});
    //char buf[65536];
    //while (true){
    //    scanf("%s",buf);
    //    auto len = ::strlen(buf);
    //    if (len==0)break;
    //    client.write(buf,len);
    //}
    return 0;
}
