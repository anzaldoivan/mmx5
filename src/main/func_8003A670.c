/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003AD18.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK player_clear_dash();
M2C_UNK set_stand_animation_by_hp(void*);

void func_8003A670(void* arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    player_clear_dash();
    if (player_check_script(arg0) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        if ((M2C_FIELD(arg0, s8*, 2) == 0) &&
            (M2C_FIELD(arg0, s8*, 0x8E) != 0)) {
            temp_v0 = M2C_FIELD(arg0, u8*, 0x91);
            var_a2 = temp_v0 < 9U;
            if (temp_v0 < 5U) {
                var_a2 = 2;
            }
            player_set_animation_frame(arg0, 0x5E, var_a2);
            temp_v1 = M2C_FIELD(arg0, u8*, 0x91);
            if (temp_v1 >= 9U) {
                M2C_FIELD(arg0, s8*, 0x44) = (s8)(temp_v1 - 8);
            }
        } else {
            set_stand_animation_by_hp(arg0);
        }
    }
}
