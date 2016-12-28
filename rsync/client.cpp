#include <cstdio>
#include <vector>
#include <muduo/net/EventLoopThread.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpClient.h>
#include <muduo/base/Condition.h>
#include <muduo/base/Logging.h>
#include "FileTransfer.pb.h"
#include "Dispatcher.h"
#include "Codec.h"

using namespace std;
using namespace muduo;

muduo::MutexLock mutex_;
muduo::Condition cond_(mutex_);
bool done=false;
//std::vector<std::vector<
class FileTransferClient{
    public:
        using FilePtr = shared_ptr<FILE> ;
        using TcpConnectionPtr = muduo::net::TcpConnectionPtr;

        //struct HashTable{
        //    HashTable(){
        //        table_.reserve(2<<16);
        //    }
        //    std::vector<std::vector<std::pair<unsigned int,int>>> table_;
        //    int * find(uint32_t sum){
        //        if (table_[sum>>16].empty())return NULL;
        //        else {
        //            auto it=table_[sum>>16].find(sum);
        //        }
        //    }
        //};
        struct Context{
            mutable std::map<unsigned int,vector<int>> hash;
        };
        FileTransferClient(net::EventLoop*loop,const net::InetAddress & addr)
            :client_(loop,addr,"FileTransferClient"),
            fp(fopen("file.receive","wb"),::fclose)
        {
            client_.setMessageCallback(
                    [this](const net::TcpConnectionPtr & conn,
                        net::Buffer * buf,
                        Timestamp ts){
                    this->onMessage(conn,buf,ts);
                    }
                    );
            client_.setConnectionCallback( 
                    [=](const TcpConnectionPtr & conn)->void{
                        this->onConnection(conn);
                    }
                    );
            dispatcher_.registerCallback<Trunk>(
                    [=](const TcpConnectionPtr& conn,Trunk*trunk)->void{
                    this->handleTrunk(conn,trunk);
                    }
                    );

        }
        void connect(){
            client_.connect();
        }
        
    private:

        void handleTrunk(const TcpConnectionPtr & ,Trunk*trunk){
            static int totalWrite = 0;
            auto str = trunk->data();
            fwrite(str.data(),1,str.size(),fp.get());
            totalWrite+=str.size();
            LOG_INFO << "write " << str.size() <<" bytes, total="<<totalWrite;
        }
        void handleWeakChecksum(const TcpConnectionPtr & conn, WeakChecksum * weak){
            auto sz = weak->sum_size();
            const Context & ctx=boost::any_cast<const Context&>(conn->getContext());
            
            //build table
            for (int i=0;i<sz;++i){
                auto it = ctx.hash.find(weak->sum(i));
                if (it==ctx.hash.end()){
                    ctx.hash[weak->sum(i)]={i};
                }
                else{
                    //rarely happens
                    ctx.hash[weak->sum(i)].push_back(i);
                }
            }
            
            //search through the file
            
        }
        void onMessage(const net::TcpConnectionPtr &conn ,
                net::Buffer* buf,
                Timestamp ){
            while (true){
                auto msg =  codec_.retrieveMessage(buf);
                if (msg.get()==NULL)break;
                dispatcher_.onMessage(conn,msg.get());
            }
        }
        void onConnection(const net::TcpConnectionPtr & conn){
            if (conn->connected()){
                //currently just shutdown
                Init initMsg;
                initMsg.set_trunksize(1024);
                initMsg.set_filename("file");
                codec_.sendMessage(conn,&initMsg);
                Context ctx;
                //conn->setContext(initMsg.filename());
                conn->setContext(std::move(ctx));
            }
            else if (conn->disconnected()){
                MutexLockGuard guard(mutex_);
                done = true;
                cond_.notify();
            }
        }
        net::TcpClient client_;
        Codec codec_;
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
    return 0;
}
