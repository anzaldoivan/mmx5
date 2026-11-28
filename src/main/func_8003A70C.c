#include "types.h"
#include "mmx5/globals.h"

extern void player_set_animation_frame(u8* obj, s32 arg1, s32 arg2);
extern void player_clear_dash(u8*);
extern void set_stand_animation_by_hp(u8* obj);

void func_8003A70C(u8* arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    if (player_check_script(arg0) == 0) {
        if (*(s8*)(arg0 + 2) == 0) {
            player_clear_dash(arg0);
            if (player_check_script(arg0) == 0) {
                arg0[5] = 2;
                arg0[6] = 0;
                if (*(s8*)(arg0 + 2) == 0 && *(s8*)(arg0 + 0x8E) != 0) {
                    temp_v0 = arg0[0x91];
                    var_a2 = temp_v0 < 9U;
                    if (temp_v0 < 5U) {
                        var_a2 = 2;
                    }
                    player_set_animation_frame(arg0, 0x5E, var_a2);
                    temp_v1 = arg0[0x91];
                    if (temp_v1 >= 9U) {
                        arg0[0x44] = temp_v1 - 8;
                    }
                } else {
                    set_stand_animation_by_hp(arg0);
                }
            }
        } else {
            func_8003B33C(arg0, 9);
            arg0[5] = 5;
            arg0[6] = 0;
        }
    }
}
