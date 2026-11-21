#include "types.h"

extern s8 D_8009A0A2;
extern u8 D_800D1C49;
extern u8 D_800FDB90_ovl27[];

void func_800FB6AC_ovl27(u8* a0) {
    if (*(u16*)(a0 + 0x88) & 1) {
        a0[3] = 0;
    } else {
        a0[3] = 1;
    }
    if (--*(s16*)(a0 + 0x88) == 0) {
        a0[3] = 1;
        if (D_8009A0A2 == 0 && D_800D1C49 == 3) {
            *(s32*)(a0 + 0x50) = 0;
        } else {
            *(u8**)(a0 + 0x50) = D_800FDB90_ovl27;
        }
        a0[7]++;
    }
}

extern s8 D_8009A0A2;
extern u8 D_800D1C49;

void func_800FB740_ovl27(u8* a0) {
    u8* p = *(u8**)(a0 + 0x7C);

    if (((s8*)p)[4] == 2) {
        if (D_8009A0A2 != 0 || D_800D1C49 != 3) {
            *(s32*)(a0 + 0x50) = 0;
            *(s16*)(a0 + 0x88) = 0x1E;
            a0[7]++;
        }
    } else if (p[0x89] == 0 && (p[0x8C] & 1)) {
        *(s16*)(a0 + 0x88) = 0x1E;
        *(s32*)(a0 + 0x50) = 0;
        a0[7]++;
    }
}

void func_800FB7D8_ovl27(u8* a0) {
    if (*(u16*)(a0 + 0x88) & 1) {
        a0[3] = 0;
    } else {
        a0[3] = 1;
    }
    if (--*(s16*)(a0 + 0x88) == 0) {
        a0[3] = 0;
        a0[4]++;
    }
}
