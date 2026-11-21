#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_08/func_800E9B0C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_init, AGPL-3.0; proven shared with X6 by exact signature 339a3fd19fc8 (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F18F4_ovl07(X4_Obj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    M2C_FIELD(arg0, s16*, 0x54) = 3;
    arg0->unk16 = 2;
    set_animation(arg0, 0x19);
}
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/rock_08/func_800E9B48.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_main, AGPL-3.0; proven shared with X6 by exact signature d83d6ae99f8d (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1930_ovl07(Ent448C* arg0) {
    X4_Obj* temp_s1 = M2C_FIELD(arg0, void**, 0x50);

    arg0->unkA = temp_s1->x_pos.i.hi;
    arg0->unkE = temp_s1->y_pos.i.hi;
    if (arg0->unk46 < 0) {
        M2C_FIELD(arg0, s16*, 0x54)--;
    }
    ((void (*)())animate_object)(arg0);
    if (temp_s1->state == 2) {
        arg0->unk4 = 2;
    } else {
        if (M2C_FIELD(arg0, s16*, 0x54) == 0) {
            arg0->unk4 = 2;
        }
        func_8002D9EC(arg0, 0x10, 0x10);
    }
}
