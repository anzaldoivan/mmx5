/* Shared body (DK-5), from the banked draft of func_800F0BE8_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EC0E8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);
M2C_UNK func_80017248();
extern s8 D_800D1C44;

void DEDUP_NAME(void* arg0) {
    s32 var_v0;
    s8 temp_s1;

    ((void (*)())func_80017248)();
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            // !FAKE: pins t to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
            register s32 t asm("$2") = M2C_FIELD(arg0, s32*, 0x84) + 1;
            M2C_FIELD(arg0, s32*, 0x84) = t;
            var_v0 = t < D_800D1C44 + 3;
        } else {
            var_v0 = M2C_FIELD(arg0, s32*, 0x84) + 1;
            M2C_FIELD(arg0, s32*, 0x84) = var_v0;
            var_v0 = var_v0 < 4;
        }
        if (var_v0 == 0) {
            temp_s1 = M2C_FIELD(arg0, s8*, 2);
            if (temp_s1 == 2) {
                func_800171E8(arg0, 0);
                M2C_FIELD(arg0, u8*, 5) = temp_s1;
                M2C_FIELD(arg0, u16*, 0x7C) = 0x78;
            } else {
                M2C_FIELD(arg0, u8*, 5) = 4;
                M2C_FIELD(arg0, u16*, 0x7C) = 0x14;
            }
            M2C_FIELD(arg0, s32*, 0x84) = 0;
        }
    }
}
