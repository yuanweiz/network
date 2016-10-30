#include <cstdio>
#include <vector>
#include <muduo/net/EventLoopThread.h>
#include <muduo/net/TcpClient.h>

using namespace std;
using namespace muduo;
//#include <muduo/net/Callbacks.h>
//#include <muduo/net/TcpConnection.h>
//
class ChatClient{
    public:
        ChatClient(net::EventLoop*loop,const net::InetAddress & addr)
            :client_(loop,addr,"ChatClient")
        {
            client_.setMessageCallback(
                    [this](const net::TcpConnectionPtr & conn,
                        net::Buffer * buf,
                        Timestamp ts){
                    this->onMessage(conn,buf,ts);
                    }
                    );
        }
        void write (const char * buf,size_t size){
            client_.connection()->send(buf,size);
        }
        
        void connect(){
            client_.connect();
        }
        
    private:
        void onMessage(const net::TcpConnectionPtr & ,
                net::Buffer* buf,
                Timestamp ){
            auto str = buf->retrieveAllAsString();
            puts(str.c_str());
        }
        net::TcpClient client_;
        //net::TcpConnectionPtr conn;
};

int main (){
    //net::EventLoop e;
    net::EventLoopThread loopThread;
    net::InetAddress addr("127.0.0.1",8765);
    ChatClient client( loopThread.startLoop(), addr);
    client.connect();
    char buf[65536];
    while (true){
        scanf("%s",buf);
        auto len = ::strlen(buf);
        if (len==0)break;
        client.write(buf,len);
    }
    return 0;
}
