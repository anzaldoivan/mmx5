#include "types.h"

void func_800F2A7C_ovl07(u8* arg0) {
    s32 v;

    if (((s8*)arg0)[2] != 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = -0x4000;
    } else {
        v = arg0[0x86];
        if (v != 0) {
            v = -0x4000;
        } else {
            v = 0x4000;
        }
        *(s32*)(arg0 + 0x20) = v;
        *(s32*)(arg0 + 0x24) = 0;
    }
    arg0[0x84] = 0;
    arg0[6]++;
}

void func_800F2AC8_ovl07(u8* p) {
    u16 t = *(u16*)(p + 0x88);

    if (t == 0) {
        p[5] = 2;
        p[6] = 0;
        return;
    }
    *(u16*)(p + 0x88) = t - 1;
}
