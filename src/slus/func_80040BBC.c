#include "types.h"

extern u8 D_80074CF4[];

s32 func_80040BBC(u8* arg0) {
    u16 flags;
    u8 d;

    d = D_80074CF4[arg0[0xE9]];
    *(u16*)(arg0 + 0xE) += (s8)d;
    arg0[0xE9] = (arg0[0xE9] + 1) & 0xF;
    flags = *(u16*)(arg0 + 0x7C);
    *(s32*)(arg0 + 0x20) = 0;
    if (!(flags & 3)) {
        return 0;
    }
    if (flags & 1) {
        if (arg0[0x89] & 1) {
            return 0;
        }
        *(s32*)(arg0 + 0x20) = *(s32*)(arg0 + 0x104);
        if (arg0[0x15] != 0) {
            return 1;
        }
        return -1;
    }
    if (arg0[0x89] & 2) {
        return 0;
    }
    *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x104);
    if (arg0[0x15] != 0) {
        return -1;
    }
    return 1;
}
