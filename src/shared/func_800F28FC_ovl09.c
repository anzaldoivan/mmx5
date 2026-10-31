/* Shared body (DK-5), from the banked draft of func_800F28FC_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8003D29C(s32, s32);
extern void func_8002C218(void);
extern s8 D_800D1C00[];
extern u8 D_8009A1F8[];
extern s32 D_800FB660_ovl09;
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void DEDUP_NAME(u8* arg) {
    s8* h;
    s32 i;
    u8* w;
    s8 t;

    if (D_800D1C00[0xF] == 0) {
        if (*(s16*)(arg + 0x7C) == 0x28) {
            w = D_8009A1F8;
            D_800FB660_ovl09 = *(s16*)(w + 0x26);
            *(s16*)(w + 0x26) = *(s16*)(w + 0x24) - 0x10;
        }
        if (--*(s16*)(arg + 0x7C) == 0) {
            func_8003D29C(0x14, 0x40);
        }
        if (**(s8**)(arg + 0x80) == 0) {
            D_800D50DC = 1;
            D_8009A42C = 1;
            D_80093E66 = 1;
            func_8002C218();
            for (i = 0; i < 0x17; i++) {
                s32 q = i / 32;
                s32 sh = 31 - (i - q * 32);
                s32 m = 1 << sh;
                D_80093DD0[q] &= ~m;
            }
            for (i = 0x1C; i < 0x3F; i++) {
                s32 q = i / 32;
                s32 sh = 31 - (i - q * 32);
                s32 m = 1 << sh;
                D_80093DD0[q] &= ~m;
            }
            h = D_800D1C00;
            t = h[0xC];
            if (t == 0xC) {
                D_80093DD0[9] = -0x10;
            }
            *(s16*)(arg + 0x7C) = 0;
            arg[6]++;
        }
    }
}
