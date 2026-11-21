/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EB070.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF334_ovl08(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else {
        ((s32(*)())apply_object_motion)(arg0);
        if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
            ((s32(*)())set_animation)(arg0, 3);
            M2C_FIELD(arg0, s8*, 5) = 2;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
            M2C_FIELD(arg0, s8*, 6) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s8*, 0x67) = -1;
        }
    }
}
