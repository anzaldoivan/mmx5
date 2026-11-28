#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void load_buffered_palette(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_800774FC[];

void func_8004C10C(u8* arg0) {
    u8* src = g_Player;

    *(s32*)(arg0 + 0x38) = *(s32*)(src + 0x38);
    *(s32*)(arg0 + 0x3C) = *(s32*)(src + 0x3C);
    *(s32*)(arg0 + 0x30) = *(s32*)(src + 0x30);
    *(s32*)(arg0 + 0x8) = *(s32*)(src + 0x8);
    *(s32*)(arg0 + 0xC) = *(s32*)(src + 0xC);
    arg0[0x47] = src[0x47];
    arg0[0x15] = src[0x15];
    if (++*(s16*)(arg0 + 0x8C) > 0x12C) {
        D_800E9560.s -= 8;
        if (D_800E9560.s < 0) {
            D_800E9560.s = 0;
        }
    } else {
        D_800E9560.s += 8;
        if (D_800E9560.s >= 0x40) {
            D_800E9560.s = 0x40;
        }
    }
    if (arg0[0x15] != 0) {
        *(s16*)(arg0 + 0xA) += D_800E9560.s;
    } else {
        *(s16*)(arg0 + 0xA) -= D_800E9560.s;
    }
    if (D_8009A420_as_s32 & 1) {
        load_buffered_palette(D_800774FC[*(s8*)(arg0 + 0x8E)], 0x13, 1);
        if (++*(s8*)(arg0 + 0x8E) == 6) {
            arg0[0x8E] = 0;
        }
    }
    if (D_800E9560.s == 0) {
        arg0[4]++;
    }
}
