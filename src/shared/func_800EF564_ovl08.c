/* Shared body (DK-5), from the banked draft of func_800EF564_ovl08 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EB2B8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800750C0;
extern M2C_UNK D_800F39DC_ovl08;
extern M2C_UNK D_800F39E4_ovl08;

void DEDUP_NAME(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800750C0;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E4_ovl08;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39DC_ovl08;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        ((s32(*)())set_animation)(arg0, 1);
        var_v0 = -0x6000;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_v0 = 0x6000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_v0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    animate_object(arg0);
    ((s32(*)())move_object)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
        }
    } else if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
    }
}
