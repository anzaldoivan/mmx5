/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC0C0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

s32 try_enter_wall_cling(void*); /* extern */
s32 func_80040BBC(void*);        /* extern */

void player_hover_hold(s32 arg0) {
    s32 temp_v0;

    if ((func_80040B6C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        temp_v0 = func_80040BBC(arg0);
        if (temp_v0 != 0) {
            player_hover_set_direction(arg0, temp_v0);
            return;
        }
        func_8003F2D8(arg0, 0x16);
    }
}
