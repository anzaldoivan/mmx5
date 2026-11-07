#include "types.h"

void func_800EF39C_ovl21(u8* arg0) {
    u8* src;
    s32 flag;
    s32 t;

    src = *(u8**)(arg0 + 0x50);
    *(u16*)(arg0 + 0x40) = *(u16*)(src + 0x40);
    *(s32*)(arg0 + 0x3C) = *(s32*)(src + 0x3C);
    *(u8*)(arg0 + 0x14) = *(u8*)(src + 0x14);
    *(u16*)(arg0 + 0x42) = *(u16*)(src + 0x42);
    *(u8*)(arg0 + 0x15) = *(u8*)(src + 0x15);
    *(u8*)(arg0 + 0x47) = 1;
    *(PairFB4BC*)(arg0 + 0x18) = *(PairFB4BC*)(arg0 + 0x8);
    flag = *(s8*)(arg0 + 0x4);
    if (flag == 0) {
        t = *(s8*)(arg0 + 0x2);
        *(s16*)(arg0 + 0x54) = 5;
        *(u8*)(arg0 + 0x3) = 1;
        *(s16*)(arg0 + 0x56) = 8;
        *(s16*)(arg0 + 0x58) = (5 - t) * 2;
        *(PairFB4BC*)(arg0 + 0x8) = *(PairFB4BC*)(src + 0x8);
        *(u8*)(arg0 + 0x4) = 1;
        *(u8*)(arg0 + 0x5) = 0;
        return;
    }
    if (*(s16*)(arg0 + 0x54) != 0) {
        *(s16*)(arg0 + 0x54) = *(s16*)(arg0 + 0x54) - 1;
        return;
    }
    t = *(s32*)(arg0 + 0x5C);
    *(s16*)(arg0 + 0x54) = 5;
    *(PairFB4BC*)(arg0 + 0x8) = *(PairFB4BC*)((u8*)t + 0x18);
}
