#include "types.h"
#include "addr.h"

extern void func_8004FD24(u8* a0);

void func_800F6BDC_ovl01(u8* a0) {
    u8* p = *(u8**)(D_1F80004C.bytes + 0x80);

    if (p[0x87] == 1) {
        func_8004FD24(a0);
        a0[4] = 6;
        a0[3] = 0;
    } else {
        *(u16*)(a0 + 0x42) |= *(u16*)(p + 0x42) & 0x8000;
    }
}
