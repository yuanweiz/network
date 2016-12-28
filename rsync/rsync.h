#ifndef __RSYNC_H
#define __RSYNC_H
#include <stdint.h>
//copy some algorithm from rsync source


namespace rsync {

uint32_t  checksum_weak(void *buf1, uint32_t len);
uint32_t checksum_strong(void  *buf, uint32_t len,void *sum);

}
#endif // __RSYNC_H
