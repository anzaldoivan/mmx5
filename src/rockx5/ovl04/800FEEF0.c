#include "types.h"
#include "mmx5/globals.h"

#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

void func_800FEEF0_ovl04(u8* a0) {
    if (D_800D1C28_as_u8 & a0[0x93]) {
        a0[0x95] = ~a0[0x93];
        a0[5]++;
    }
    func_8002D9EC(a0, 0x10, 0x10);
}
#undef D_800D1C28_as_u8

extern u8 D_800D1C00[];

void func_800FEF40_ovl04(u8* obj) {
    s32 limit = 300;

    D_800D1C00[0x28] &= ~obj[0x93];
    if (D_800D1C00[0x26] & 2) {
        limit = 50;
    }
    if (++*(s32*)(obj + 0x84) >= limit) {
        *(s32*)(obj + 0x84) = 0;
        obj[5]++;
    }
}
