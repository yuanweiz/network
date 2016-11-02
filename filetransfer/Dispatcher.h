#ifndef __DISPATCHER_H
#define __DISPATCHER_H
// a demo of Mr.Chen Shuo's design
// of Dispatcher class 
#include <map>
#include <functional>
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
        using CallBack = std::function<void(Message*)>;
        template <class T> void registerCallback(std::function<void(T*)> callbackT){
            auto callback = [=](Message* msg) -> void {
                callbackT(static_cast<T*>(msg));
            };
            callbacks_[T::descriptor()] = callback;
        }
        void onMessage(Message* msg);
    private:
        std::map< const Descriptor*, CallBack> callbacks_;
};
#endif// __DISPATCHER_H
