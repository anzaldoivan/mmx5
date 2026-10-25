/* Shared body (DK-5), from the banked draft of func_800EEE84_ovl08 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EABCC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK); /* extern */
M2C_UNK func_80017248();               /* extern */
extern M2C_UNK D_80074EE0;
extern M2C_UNK D_800750C0;
extern M2C_UNK D_800F39DC_ovl08;
extern M2C_UNK D_800F39E0_ovl08;
extern M2C_UNK D_800F39E4_ovl08;

void DEDUP_NAME(void* arg0) {
    switch (M2C_FIELD(arg0, s8*, 6)) {
    case 0:
        M2C_FIELD(arg0, s8*, 6)++;
        func_800171E8(arg0, 5);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    case 1:
        if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
            M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_80074EE0;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E0_ovl08;
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39E0_ovl08;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s8*, 6)++;
            func_800171E8(arg0, 6);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            ((void (*)(void*, s32))func_800171E8)(arg0, 1);
            M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800750C0;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E4_ovl08;
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39DC_ovl08;
            M2C_FIELD(arg0, s8*, 5) = 1;
            M2C_FIELD(arg0, s8*, 6) = 0;
            {
                // !FAKE: pins l to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
                register s32 l asm("$3") = M2C_FIELD(arg0, u8*, 0x80);
                M2C_FIELD(arg0, u8*, 0x82) = 0x78;
                M2C_FIELD(arg0, u8*, 0x80) = l & 0xFE;
            }
        }
        break;
    }
    func_80017248(arg0);
}
