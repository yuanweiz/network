#ifndef __DISPATCHER_H
#define __DISPATCHER_H
// a demo of Mr.Chen Shuo's design
// of Dispatcher class 
#include <map>
#include <functional>
#include <muduo/net/TcpConnection.h>
namespace google{
namespace protobuf{
    class Message;
    class Descriptor;
}
}
class Dispatcher{
    public:
        using Message = google::protobuf::Message;
        using Descriptor = google::protobuf::Descriptor;
        using TcpConnectionPtr = muduo::net::TcpConnectionPtr;
        using CallBack = std::function<void(const TcpConnectionPtr&,Message*)>;
        Dispatcher();
        template <class T> void registerCallback
        (std::function<void(const TcpConnectionPtr& ,T*)> callbackT){
        //template <class T, class Func> 
        //    void registerCallback(const Func& callbackT){
            CallBack callback = [=](const TcpConnectionPtr & conn,Message* msg) -> void {
                callbackT( conn,static_cast<T*>(msg));
            };
            callbacks_[T::descriptor()] = callback;
        }
        void onMessage(const TcpConnectionPtr & ,Message* );
        void setMethodMissingCallback(const CallBack &);
    private:
        CallBack methodMissingCallback_;
        std::map< const Descriptor*, CallBack> callbacks_;
};
#endif// __DISPATCHER_H
