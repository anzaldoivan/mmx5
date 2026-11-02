#include "types.h"

extern s32 func_800F033C_ovl04(void);
extern u32 func_8002DF78(void);
extern s16 D_8009A206;
extern s8 D_800D1C00[];

void func_800FBEF8_ovl04(u8* o) {
    s8* g;
    s32 v;

    if (func_800F033C_ovl04() != 0) {
        if (D_8009A206 == 0x170 || D_8009A206 == 0x320) {
            *(s8*)(o + 0x8C) = 1;
            *(s16*)(o + 0x88) = (func_8002DF78() & 1) + 8;
        } else if (D_8009A206 == 0x280) {
            *(s8*)(o + 0x8C) = -1;
            *(s16*)(o + 0x88) = (u8)(func_8002DF78() % 50) + 0x28;
        }
        if (*(s8*)(o + 0x8C) == 1) {
            *(s32*)(o + 0x84) += 0x10000;
        } else if (*(s8*)(o + 0x8C) == -1) {
            *(s32*)(o + 0x84) += -0x10000;
        }
        g = D_800D1C00;
        if (g[0x27] != 0) {
            *(s32*)(o + 0x84) += -0x10000;
            g[0x27] = 0;
        }
        v = *(s32*)(o + 0x84);
        if (v > 0x1FFFFF) {
            *(s32*)(o + 0x84) = 0x200000;
            *(s8*)(o + 0x8C) = 0;
        } else if (v < 0) {
            *(s32*)(o + 0x84) = 0;
            *(s8*)(o + 0x8C) = 0;
        }
    }
}
