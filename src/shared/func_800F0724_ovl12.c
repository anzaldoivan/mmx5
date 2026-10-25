/* Shared body (DK-5), from the banked draft of func_800F0724_ovl12 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_45/func_800FBF00.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017248(); /* extern */

void DEDUP_NAME(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 3) {
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s32*, 0x20) = -0x10000;
        } else {
            M2C_FIELD(arg0, s8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0x10000;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x2222;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    ((M2C_UNK(*)())func_80017248)();
}
