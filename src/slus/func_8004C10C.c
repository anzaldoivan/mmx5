#include "types.h"

extern void func_8003CEAC(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_800774FC[];
extern u8 D_8009A0A0[];
extern s32 D_8009A420;
extern s16 D_800E9560;

void func_8004C10C(u8* arg0) {
    u8* src = D_8009A0A0;

    *(s32*)(arg0 + 0x38) = *(s32*)(src + 0x38);
    *(s32*)(arg0 + 0x3C) = *(s32*)(src + 0x3C);
    *(s32*)(arg0 + 0x30) = *(s32*)(src + 0x30);
    *(s32*)(arg0 + 0x8) = *(s32*)(src + 0x8);
    *(s32*)(arg0 + 0xC) = *(s32*)(src + 0xC);
    arg0[0x47] = src[0x47];
    arg0[0x15] = src[0x15];
    if (++*(s16*)(arg0 + 0x8C) > 0x12C) {
        D_800E9560 -= 8;
        if (D_800E9560 < 0) {
            D_800E9560 = 0;
        }
    } else {
        D_800E9560 += 8;
        if (D_800E9560 >= 0x40) {
            D_800E9560 = 0x40;
        }
    }
    if (arg0[0x15] != 0) {
        *(s16*)(arg0 + 0xA) += D_800E9560;
    } else {
        *(s16*)(arg0 + 0xA) -= D_800E9560;
    }
    if (D_8009A420 & 1) {
        func_8003CEAC(D_800774FC[*(s8*)(arg0 + 0x8E)], 0x13, 1);
        if (++*(s8*)(arg0 + 0x8E) == 6) {
            arg0[0x8E] = 0;
        }
    }
    if (D_800E9560 == 0) {
        arg0[4]++;
    }
}
