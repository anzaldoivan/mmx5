/* Shared body (DK-5), from the banked draft of func_800EFDEC_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EA448.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);
extern M2C_UNK D_80074DA0;
extern M2C_UNK D_800F96CC_ovl03;
extern M2C_UNK D_800F96D0_ovl03;

void DEDUP_NAME(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x3000;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F96CC_ovl03;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F96D0_ovl03;
    M2C_FIELD(arg0, void**, 0x58) = &D_80074DA0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F96D0_ovl03;
    {
        // !FAKE: pins one to $5; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 one asm("$5") = 1;
        M2C_FIELD(arg0, u8*, 0x3) = one;
        {
            // !FAKE: pins k to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
            register s32 k asm("$3") = 5;
            M2C_FIELD(arg0, u8*, 0x60) = k;
        }
        M2C_FIELD(arg0, u8*, 0x5C) = one;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = (u8)(M2C_FIELD(arg0, u8*, 0x4) + 1);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    func_800171E8(arg0, 2);
}
