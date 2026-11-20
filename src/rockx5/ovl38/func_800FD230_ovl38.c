#include "types.h"

void func_800FD230_ovl38(u8* p) {
    p[0x47] = (*(u8**)(p + 0x7C))[0x47];
    if (*(u16*)(p + 0x88) & 1) {
        p[3] = 1;
    } else {
        p[3] = 0;
    }
    if (--*(s16*)(p + 0x88) == 0) {
        p[3] = 0;
        p[4]++;
    }
}
