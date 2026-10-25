#include "types.h"

extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern void func_8003CEAC(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_800D1C00[];

void func_8003D5E0(u8* arg0) {
    u8* d = D_800D1C00;
    s32 v = d[0x49];

    arg0[0xFA] = v;
    *(s32*)(arg0 + 0xFC) = *(s32*)(D_800D1C00 + arg0[0xFA] * 4 + 0x88);
    if (v == 3) {
        arg0[0xC9] = 0;
        arg0[0x14A] = 0;
        func_8003D4C0(1, 0x1B, 8, 0);
        func_8003D4C0(1, 0x1B, 9, 0);
        func_8003CEAC(0x49, 0x14, 1);
    } else {
        arg0[0xC9] = d[0x4C];
        arg0[0x14A] = d[0x4B];
    }
}
