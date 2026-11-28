/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004C120.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

s32 func_8002DFB0();
void func_80032CEC();
s32 rsin(s32);
s32 rcos(s32);
extern s32 D_8007BA74[];
extern s32 D_8007BA84[];

#define C120_W(p, o) (*(s32*)((u8*)(p) + (o)))
#define C120_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define C120_H(p, o) (*(u16*)((u8*)(p) + (o)))

void func_80051C2C(void* arg0) {
    s32 r;

    C120_W(arg0, 0x1C) =
        rcos(C120_H(arg0, 0x38)) * D_8007BA74[C120_B(arg0, 0x3A) + 1] * 0x10;
    C120_W(arg0, 0x20) =
        rsin(C120_H(arg0, 0x38)) * D_8007BA74[C120_B(arg0, 0x3A) + 1] * 0x10;
    C120_W(arg0, 0x24) =
        rcos((C120_H(arg0, 0x38) + D_8007BA84[func_8002DFB0() % 3]) & 0xFFF) *
        D_8007BA74[C120_B(arg0, 0x3A)] * 0x10;
    C120_W(arg0, 0x28) =
        rsin((C120_H(arg0, 0x38) + D_8007BA84[func_8002DFB0() % 3]) & 0xFFF) *
        D_8007BA74[C120_B(arg0, 0x3A)] * 0x10;
    C120_W(arg0, 0x2C) = 0;
    C120_W(arg0, 0x30) = 0;
    r = func_8002DFB0();
    C120_B(arg0, 0x4)++;
    C120_B(arg0, 0x3B) = r % 7;
    func_80032CEC(arg0);
}

#undef C120_W
#undef C120_B
#undef C120_H
