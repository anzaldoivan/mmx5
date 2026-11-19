#include "types.h"
#include "mmx5/globals.h"

void func_800FFF18_ovl04(u8* a0) {
    u8* p = *(u8**)(a0 + 0x50);

    *(s32*)(a0 + 0x8) = *(s32*)(p + 0x18);
    *(s32*)(a0 + 0xC) = *(s32*)(p + 0x1C);
    a0[0x47] = p[0x47];
    if (*(s8*)(p + 4) >= 2) {
        a0[4]++;
    }
    if (a0[2] & 1) {
        func_8002D9EC(a0, 0x10, 0x10);
    } else {
        a0[3] = 0;
    }
}
