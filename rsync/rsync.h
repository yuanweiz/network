#ifndef __RSYNC_H
#define __RSYNC_H
#include <stdint.h>
//copy some algorithm from rsync source


namespace rsync {

uint32_t  checksum_weak(char *buf1, uint32_t len);
void checksum_strong(unsigned char *buf, uint32_t len, unsigned char *sum);

}
#endif // __RSYNC_H
