#include "types.h"

extern s32 func_8004FD90(u8*, s32, s32, s32);
extern s8 D_800D1C00[];

void func_800FF778_ovl07(u8* arg0) {
    s8* p;
    s8* q;
    s8 v;

    p = D_800D1C00;
    if (p[0x28] != 0) {
        *(u16*)(arg0 + 0x42) |= 0x8000;
        arg0[0x54]++;
        p[0x28] = 0;
    } else {
        *(u16*)(arg0 + 0x42) &= 0x7FFF;
    }
    v = ((s8*)arg0)[0x54];
    q = D_800D1C00;
    if (v == 8) {
        func_8004FD90(arg0, 1, 0, 0x30);
        func_8004FD90(arg0, 1, 0, 0x30);
        arg0[0x55] = 0;
        arg0[0x5]++;
        return;
    }
    if (v == q[0x26]) {
        ((u8*)q)[0x27] |= 1;
        arg0[0x4]++;
    }
}
