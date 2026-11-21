/* Adapted from mmx6 @c1c892d src/shared/rock_45/func_800FC74C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800D1C0F;

void func_800F0FEC_ovl12(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        D_800D1C0F = 0x10;
        clear_object_slot();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x48, arg0);
        M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    }
    func_8002D9EC(arg0, 0x40, 0x40);
    animate_object(arg0);
    move_object(arg0);
}
