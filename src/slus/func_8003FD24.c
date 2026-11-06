#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u8 D_800D1D10;

void func_8003FD24(u8* arg0) {
    s32 hi;
    s32 lo;
    s8 state;
    s32 count;

    if (!(*(u16*)(arg0 + 0x7C) & 0x20)) {
        if (!(D_800D1D10 & 1)) {
            return;
        }
        if (*(s8*)(arg0 + 0x93) != 0) {
            return;
        }
    }
    state = *(s8*)(arg0 + 0x9C);
    if (state == 2) {
        return;
    }
    if (arg0[0xFA] == 3 && state == 1) {
        arg0[0x9C] = 2;
        return;
    }
    hi = 0x5A;
    lo = 0x19;
    count = arg0[0x9E] + 1;
    arg0[0x9E] = count;
    if (*(s32*)(arg0 + 0xFC) & 0x2000) {
        hi = 0x2D;
        lo = 0xC;
    }
    if ((count & 0xFF) == lo) {
        func_80016490(1, 7, arg0);
        arg0[0x9C] = 1;
        return;
    }
    if ((count & 0xFF) == hi) {
        arg0[0x9C] = 2;
    }
}
