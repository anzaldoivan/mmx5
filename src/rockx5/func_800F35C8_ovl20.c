#include "types.h"

extern u8* func_8002D27C(void);
extern u16 D_800F5664_ovl20[][4];

void func_800F35C8_ovl20(u8* arg0) {
    s8 kind;
    u16 w;
    u16 h;
    u8* child;
    s32 one;

    one = 1;
    arg0[0x37] = one;
    *(s8*)arg0 = -0x6D;
    kind = arg0[2];
    arg0[0x36] = 0x22;
    *(s16*)(arg0 + 0x34) = 0x15;
    *(u16*)(arg0 + 0xA) = D_800F5664_ovl20[kind >> 4][0];
    *(u16*)(arg0 + 0xE) = D_800F5664_ovl20[kind >> 4][1];
    w = D_800F5664_ovl20[kind >> 4][2];
    *(u16*)(arg0 + 0x38) = w;
    h = D_800F5664_ovl20[kind >> 4][3];
    *(u16*)(arg0 + 0x3C) = w;
    *(u16*)(arg0 + 0x1E) = w;
    *(u16*)(arg0 + 0x26) = w;
    *(s16*)(arg0 + 0x1A) = -h;
    *(s16*)(arg0 + 0x22) = -h;
    *(u16*)(arg0 + 0x3A) = h;
    *(u16*)(arg0 + 0x2A) = h;
    *(u16*)(arg0 + 0x32) = h;
    if (kind == 0x50) {
        *(u16*)(arg0 + 0xA) = 0xC0;
        *(u16*)(arg0 + 0xE) = 0x48;
        arg0[0x36] = 3;
        *(s16*)(arg0 + 0x16) = -w;
        *(s16*)(arg0 + 0x2E) = -w;
        arg0[5] = 2;
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0xA;
            child[2] = one;
            *(u8**)(child + 0x50) = arg0;
        }
    }
    arg0[4]++;
}
