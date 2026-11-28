#include "types.h"
#include "mmx5/globals.h"

void func_800EFF84_ovl04(u8* arg0) {
    if (D_8009A0AA >= 0x12D1) {
        ((s32(*)())func_8003D29C)(0x14, 0x40);
        D_8009A1F8.bg[0].unk26 = 0x12C0;
        D_8009A1F8.bg[0].unk24 = 0x12C0;
        arg0[6]++;
    }
}

#include "shared/func_800EFFE4_ovl04.c"

extern s8 D_8009A0A5;

void func_800EFFF8_ovl04(u8* arg0) {
    if (D_8009A0A5 == 0x14) {
        ((s32(*)())func_8003D29C)(0x1D, 0x40);
        arg0[6]++;
    }
}

void func_800F0044_ovl04(u8* arg0) {
    if (D_8009A0AA >= 0x12EE) {
        ((s32(*)())func_8003D29C)(0x14, 0x40);
        arg0[6]++;
    }
}

extern s8 D_8009A0A5;
extern s8 D_800D1C1D;

void func_800F0090_ovl04(u8* a0) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = D_8009A1F8.u;
        if (*(s16*)(p + 0xA) == 0x12C0) {
            *(s16*)(p + 0x5E) = 0x370;
            *(s16*)(p + 0x62) = 0;
            p[0xA0] = 1;
            D_800D1C1D = 5;
            a0[6] = 0;
            a0[5]++;
        }
    }
}
