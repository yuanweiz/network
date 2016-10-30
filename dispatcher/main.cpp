#include <functional>
#include "first.pb.h"
#include <cstdio>
#include <map>
// a demo of Mr.Chen Shuo's design
// of Dispatcher class 
using namespace std;
using ::google::protobuf::Message;
using ::google::protobuf::Descriptor;

class Dispatcher{
    public:
        using CallBack = function<void(Message*)>;
        template <class T> void registerCallback(function<void(T*)> callbackT){
            auto callback = [=](Message* msg) -> void {
                callbackT(static_cast<T*>(msg));
            };
            callbacks_[T::descriptor()] = callback;
        }
        void doit(Message* msg){
            const Descriptor * desc = msg->GetDescriptor();
            //auto it = callbacks_.find(desc);
            //
            CallBack& callback = callbacks_[desc];
            callback(msg);
        }
    private:
        map< const Descriptor*, CallBack> callbacks_;
};

void handleInt32Msg( tutorial::Int32Msg* msg){
    printf( "%d\n",msg->val());
}
void handleStringMsg(tutorial::StringMsg*msg){
    printf("%s\n",msg->name().c_str());
}
int main (){
    Dispatcher dispatcher;
    tutorial::Int32Msg intmsg;
    tutorial::StringMsg strmsg;
    intmsg.set_val(42);
    strmsg.set_name("name");

    //register callbacks
    dispatcher.registerCallback<tutorial::Int32Msg>(handleInt32Msg);
    dispatcher.registerCallback<tutorial::StringMsg>(handleStringMsg);

    //dispatch
    Message * msg;
    msg = & intmsg;
    dispatcher.doit(msg);
    msg = & strmsg;
    dispatcher.doit(msg);

    return 0;
}
