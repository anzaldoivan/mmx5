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
