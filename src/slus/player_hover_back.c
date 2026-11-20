/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC240.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 try_enter_wall_cling(void*);                       /* extern */
M2C_UNK player_set_animation_shooting(void*, M2C_UNK); /* extern */
s32 func_80040BBC(void*);                              /* extern */

void player_hover_back(void* arg0) {
    s32 temp_v0;
    s8 var_v0;

    if ((func_80040B6C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        temp_v0 = func_80040BBC(arg0);
        if (temp_v0 != 0) {
            if (temp_v0 > 0) {
                player_set_animation_shooting(arg0, 0x17);
                var_v0 = 3;
                goto block_7; // !FAKE: control flow kept from the mmx6 twin
            }
            move_object(arg0);
            func_8003F2D8(arg0, 0x19);
            return;
        }
        player_set_animation_shooting(arg0, 0x1A);
        var_v0 = 6;
    block_7:
        M2C_FIELD(arg0, s8*, 6) = var_v0;
    }
}
