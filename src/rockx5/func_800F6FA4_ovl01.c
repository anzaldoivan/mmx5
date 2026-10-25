#include "types.h"

extern u8* func_8002C938();
extern u8 D_800FCFF0_ovl01[];

void func_800F6FA4_ovl01(s32 arg0, u8 arg1) {
    u8* p = func_8002C938();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x1A;
        p[2] = D_800FCFF0_ovl01[arg1 * 8];
        *(u16*)(p + 0xA) = *(u16*)(D_800FCFF0_ovl01 + arg1 * 8 + 4);
        *(u16*)(p + 0xE) = *(u16*)(D_800FCFF0_ovl01 + arg1 * 8 + 6);
        *(s32*)(p + 0x10) = 0;
        *(s32*)(p + 0x80) = arg0;
    }
}
