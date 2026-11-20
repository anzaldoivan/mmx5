/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80036364.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80035DA4(void* arg0) {
    s8 temp_v1;

    ((void (*)())animate_object)(arg0);
    apply_object_motion(arg0);
    temp_v1 = M2C_FIELD(arg0, s8*, 6);
    if (temp_v1 == 2) {
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            func_80039ECC(arg0);
        }
    } else if (temp_v1 == 1) {
        if (M2C_FIELD(arg0, s32*, 0x20) <= 0) {
            ((void (*)(void*, s32))func_8003B33C)(arg0, 0x52);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    } else if (temp_v1 == 0) {
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            M2C_FIELD(arg0, u8*, 0x45) = M2C_FIELD(arg0, u8*, 0x45) & 0x3F;
            play_sound(1, 1, arg0);
        }
        if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            ((void (*)(void*, s32))func_8003B33C)(arg0, 0xB);
            M2C_FIELD(arg0, s8*, 0x67) = -1;
        }
        if ((M2C_FIELD(arg0, s8*, 0x67) == -1) &&
            (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
            ((void (*)(void*, s32))func_8003B33C)(arg0, 0x51);
            M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}
