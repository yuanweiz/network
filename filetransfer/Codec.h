#ifndef __CODEC_H
#define __CODEC_H
#include <muduo/net/TcpConnection.h>
#include <functional>

//a simple transfer protocal which supports resume/pause
//if a file named `Foo` is being transfered, then the client
//creates two files named Foo.data and Foo.idx
//
//Foo.data consists of several trunks. and Foo.idx consists of
//corresponding number of checksums.
//
//The server doesn't store the downloading state, it only sends
//a request to get the starting offset of file, e.g.:
//
//|-------|-------|-------|-------|---|
//  trunk  trunk    trunk   trunk   \----> broken trunk
//
//|checksum|checksum|checksum|chec|
//                              \------> broken checksum
//
// in this case, the server sends a request on connection established,
// and client responses "offset 3" ( 0-based index)
//
// other calls are: stop,resume,pause, no "start" is supported now

namespace google{
namespace protobuf{
class Message;
}
}
class Codec {
    public:
        using TcpConnectionPtr=muduo::net::TcpConnectionPtr;
        using Buffer=muduo::net::Buffer;
        using Message = google::protobuf::Message;
        Codec();
        ~Codec();

        std::unique_ptr<Message> retrieveMessage( Buffer* buf );
        void sendMessage(const TcpConnectionPtr& conn, Message*msg );
        
    private:
        //empty??
};
#endif// __CODEC_H

