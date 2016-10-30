#include <cstdio>
#include <vector>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Callbacks.h>
//#include <muduo/net/TcpConnection.h>
using namespace std;
using namespace muduo;
class ChatServer{
    public:
        ChatServer (net::EventLoop* e, const net::InetAddress & addr)
            :server_(e, addr,"ChatServer")
        {
            //use lambda to capture this
            server_.setConnectionCallback(
                    [this](const net::TcpConnectionPtr & conn) {
                        this->onConnection(conn);
                    }
                    );
            server_.setMessageCallback(
                    [this](const net::TcpConnectionPtr & conn,net::Buffer*buf,Timestamp t_){
                        this->onMessage(conn,buf,t_);
                    }
                    );
        }

        //forward callbacks
        void onConnection(const net::TcpConnectionPtr & conn) {
            if (conn->connected()){
                char info[] = "Connection Established\n";
                std::string broadcastInfo = "New user connected\n";
                conn->send(info,sizeof(info));
                for (auto & existed_conn:connections_){
                    existed_conn->send(broadcastInfo.data(),broadcastInfo.size());
                }
                connections_.push_back(conn);
            }
            else if (conn->disconnected()){
                //TODO: use std.set?
                auto it = std::find_if( connections_.begin(), connections_.end(),
                        [&](const net::TcpConnectionPtr & c)->bool{
                            return c.get()==conn.get();
                        });
                connections_.erase(it);
                std::string msg("Someone left the chatting room\n");
                for (auto & conn_ :connections_){
                    conn_->send(msg);
                }
            }
            //conn->shutdown();
        }
        
        void onMessage (const net::TcpConnectionPtr & conn,
                net::Buffer*buf,
                Timestamp )
        {
            //std::string s = buf->retrieveAllAsString();
            auto str = buf->retrieveAllAsString();
            for (auto & existed_conn:connections_){
                if (existed_conn.get()!=conn.get()) //bad smell
                    existed_conn->send(str.data(),str.size());
            }
        }

        void start(){
            server_.start();
        }
        
    private:
        net::TcpServer server_;
        vector<net::TcpConnectionPtr> connections_;
};
int main (){
    net::EventLoop e;
    net::InetAddress addr(8765); 
    ChatServer server(&e, addr);
    server.start();
    e.loop();
    return 0;
}
