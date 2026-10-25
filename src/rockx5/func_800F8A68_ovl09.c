#include "types.h"
#include "addr.h"

void func_800F8A68_ovl09(u8* arg0) {
    u8* p;

    if (arg0[0x47] == 0) {
        p = *(u8**)(D_1F80004C.bytes + 0x80);
        p[0x85] |= 1 << (((s8*)arg0)[2] - 1);
        arg0[6]++;
    }
}
