/* Shared body (DK-5), from the banked draft of func_800FA564_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern s16 D_8009A0AA;
extern s8 D_800D1C0C;
extern u8 D_800FD5B0_ovl01[];
extern u8 D_800FD5B4_ovl01[];
extern u16 D_800FDA5C_ovl01[];
extern u16 D_800FDA98_ovl01[];

void DEDUP_NAME(u8* obj) {
    s32 base;
    u16 v;

    base = 0x1F0;
    if (D_800D1C0C != 0xC) {
        base = 0x24F0;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x4000;
        DEDUP_CALLEE(obj, 2);
        obj[0x15] = 0x40;
        obj[0x62] = 0;
        *(u8**)(obj + 0x54) = D_800FD5B4_ovl01;
        *(u8**)(obj + 0x50) = D_800FD5B0_ovl01;
        v = D_800FDA98_ovl01[D_800FDA5C_ovl01[(D_8009A0AA - base) / 16]];
        obj[6] = 3;
        *(u16*)(obj + 0xA) = v;
    }
}
