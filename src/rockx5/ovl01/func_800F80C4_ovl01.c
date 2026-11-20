#include "types.h"
#include "addr.h"

extern u8 D_800FD4EC_ovl01[][2];

void func_800F80C4_ovl01(u8* arg0) {
    if (((s8*)arg0)[0x45] == 0x50) {
        arg0[5] = 2;
        arg0[4] = 0;
        return;
    }
    D_1F80004C.bytes[0x84] = -D_800FD4EC_ovl01[((s8*)arg0)[0x45]][0] - 8;
    D_1F80004C.bytes[0x86] = D_800FD4EC_ovl01[((s8*)arg0)[0x45]][0];
    D_1F80004C.bytes[0x85] = -D_800FD4EC_ovl01[((s8*)arg0)[0x45]][1];
    D_1F80004C.bytes[0x87] = D_800FD4EC_ovl01[((s8*)arg0)[0x45]][1] * 2;
}
