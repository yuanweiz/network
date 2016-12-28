#include "rsync.h"
#include <openssl/md5.h>
namespace rsync{

using uint32 = uint32_t;
using int32 = int32_t;
using schar = char;
const int  CHAR_OFFSET=0;

uint32 checksum_weak(void *buf1, int32 len)
{
    int32 i;
    uint32 s1, s2;
    schar *buf = (schar *)buf1;

    s1 = s2 = 0;
    for (i = 0; i < (len-4); i+=4) {
	s2 += 4*(s1 + buf[i]) + 3*buf[i+1] + 2*buf[i+2] + buf[i+3] +
	  10*CHAR_OFFSET;
	s1 += (buf[i+0] + buf[i+1] + buf[i+2] + buf[i+3] + 4*CHAR_OFFSET);
    }
    for (; i < len; i++) {
	s1 += (buf[i]+CHAR_OFFSET); s2 += s1;
    }
    return (s1 & 0xffff) + (s2 << 16);
}

uint32_t checksum_strong( void *buf, uint32_t len,  void *sum){
    ::MD5((const unsigned char*)buf,len,( unsigned char*)sum);
    return 128;//hacky way
}

}
