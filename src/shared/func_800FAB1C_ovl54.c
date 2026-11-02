/* Shared body (DK-5), from the banked draft of func_800FAB1C_ovl54 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A2A3;
extern u8 D_800FAD54_ovl54[];
extern u8 D_800FAF54_ovl54[];
extern u8 D_800FB154_ovl54[];
extern u8 D_800FB354_ovl54[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);

void DEDUP_NAME(u8* arg0) {
    s32 t;

    if (D_80091C44 == 0) {
        t = *(u16*)(arg0 + 4) + 1;
        *(s16*)(arg0 + 4) = t;
        func_8002C3CC(D_800FAF54_ovl54, D_800FAD54_ovl54, 0x100, 0x3C - (s16)t,
                      0x3C);
        func_8002C338(0x60, D_800FAF54_ovl54, 0x10);
        func_8002C3CC(D_800FB354_ovl54, D_800FB154_ovl54, 0x100,
                      *(s16*)(arg0 + 4), 0x3C);
        func_8002C338(0x70, D_800FB354_ovl54, 0x10);
        if (*(s16*)(arg0 + 4) >= 0x3C) {
            *(s16*)(arg0 + 4) = 0;
            D_8009A2A3 = 0;
            arg0[1]++;
        }
    }
}
