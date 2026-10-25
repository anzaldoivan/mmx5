/* Shared body (DK-5), from the banked draft of func_800F1C24_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800ECC78.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"
#define M2C_UNK s32

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_800171E8(void*, M2C_UNK);
M2C_UNK func_8002D89C();
s32 func_8002DF78();
extern M2C_UNK D_8007B804;

void DEDUP_NAME(void* arg0) {
    u8* s;

    FX(arg0, u8, 0x3) = 1;
    FX(arg0, s32, 0x38) = 0;
    s = D_1F80001C.bytes;
    FX(arg0, u8*, 0x3C) = s + FX(s, s32, 0x8);
    FX(arg0, void*, 0x30) = &D_8007B804;
    FX(arg0, s16, 0x40) = 0;
    if (FX(arg0, s8, 0x54) != 2) {
        FX(arg0, s16, 0x42) = 0x7805;
    } else {
        FX(arg0, s16, 0x42) = 0x7806;
    }
    if (FX(arg0, s8, 0x7) == 0) {
        FX(arg0, u8, 0x16) = 1;
    }
    func_800171E8(arg0, FX(arg0, s8, 0x54));
    {
        // !FAKE: pins r to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 r asm("$2") = FX(arg0, u8, 0x4) + 1;
        FX(arg0, u8, 0x4) = r;
    }
    FX(arg0, s8, 0x7) = func_8002DF78() & 1;
    func_8002D89C(arg0);
}
