#include "Dispatcher.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

//Dispatcher::Dispatcher(){
//}
//Dispatcher::~Dispatcher(){
//}

void onMessage(Message* msg){
}
void Dispatcher::onMessage(Message* msg){
            const Descriptor * desc = msg->GetDescriptor();
            CallBack& callback = callbacks_[desc];
            callback(msg);
}
