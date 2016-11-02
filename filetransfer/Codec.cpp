#include "Codec.h"
#include "FileTransfer.pb.h"

void Codec::sendMessage(const Codec::TcpConnectionPtr& conn, Codec::Message*msg ){
    //FIXME: by now it is correct, but I think using raw Buffer* is no good?
    //the protocal is the same as Mr.Chen's book's
    //
    //|----len----|--nameLen--|---nameStr ended in zero---|----Contents-----|
    //
    std::string typeName=msg->GetTypeName();
    std::string contents=msg->SerializeAsString();
    int32_t nameLen = typeName.size()+1; //including zero
    int32_t len = msg->ByteSize()+nameLen+2*sizeof(int32_t);
    Buffer* buf = conn->outputBuffer();
    buf->appendInt32(len);
    buf->appendInt32(nameLen);
    buf->append(typeName.c_str(),nameLen); //with zero
    buf->append(contents);
    conn->send(buf);
    return ;
}

std::unique_ptr<Codec::Message> Codec::retrieveMessage(Codec::Buffer *buf){
    using Uptr = std::unique_ptr<Message>;
    auto readableBytes = buf->readableBytes();
    if (readableBytes < sizeof (int32_t) ){
        return Uptr{} ; //can't retrieve
    }
    int32_t len = buf->peekInt32();
    if (len < static_cast<int32_t> (readableBytes)){
        return Uptr{};
    }
    buf->readInt32(); //len, discard it
    int32_t nameLen = buf->readInt32();
    auto contentLen = len-2*sizeof (int32_t)-nameLen;
    std::string nameStr( buf->peek(),nameLen);
    buf->retrieve(nameLen);
    auto * descriptorPool = ::google::protobuf::DescriptorPool::generated_pool();
    auto * descriptor = descriptorPool->FindMessageTypeByName(""); //contain type metadata
    Message * msg = ::google::protobuf::MessageFactory::generated_factory()
        ->GetPrototype(descriptor)
        ->New(); //on-heap object, remember to delete it
    Uptr up_msg(msg);
    msg->ParseFromArray(buf->peek(),contentLen);
    buf->retrieve(contentLen);
    return up_msg;
}
Codec::Codec() {
}
Codec::~Codec(){
}
