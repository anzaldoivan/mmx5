#include "types.h"
#include "addr.h"

extern u8 D_800FEB34_ovl39[];

void func_800FCDA4_ovl39(u8* arg0) {
    u8 c;

    if (D_1F80004C.bytes[0x8B] == 1) {
        D_1F80004C.bytes[0x8B] = 0;
        c = ++D_1F80004C.bytes[0x87];
        c = D_800FEB34_ovl39[c + D_1F80004C.bytes[0x86] * 2];
        arg0[6] = 0;
        arg0[5] = c;
    }
}
