#include "Dispatcher.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

//Dispatcher::Dispatcher(){
//}
//Dispatcher::~Dispatcher(){
//}

using Message=Dispatcher::Message;
using TcpConnectionPtr = muduo::net::TcpConnectionPtr;
Dispatcher::Dispatcher(){

}
void Dispatcher::onMessage(const TcpConnectionPtr & conn,Message* msg){
    if (!msg)
        return;
    const Descriptor * desc = msg->GetDescriptor();
    auto it = callbacks_.find(desc);
    //method missing
    if (it==callbacks_.end() && methodMissingCallback_){
        methodMissingCallback_(conn,msg);
    }
    else {
        it->second(conn,msg);
    }
}

void Dispatcher::setMethodMissingCallback(const CallBack& callback){
    methodMissingCallback_ = callback;
}
