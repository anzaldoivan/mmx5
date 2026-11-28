#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void player_clear_dash(u8*);
extern s32 func_8003EF28(u8* arg0);
extern s32 func_800437FC(u8* arg0);
extern s32 player_check_dash_jump_walk(u8* arg0);
extern s32 func_8004387C(u8* arg0);
extern void player_set_animation_shooting(u8* arg0, s32 arg1);

void func_8003A9AC(u8* arg0) {
    play_sound(1, 2, arg0);
    arg0[0x67] = 0;
    player_clear_dash(arg0);
    if (player_check_script(arg0) == 0 && func_8003EF28(arg0) == 0 &&
        func_800437FC(arg0) == 0 && player_check_dash_jump_walk(arg0) == 0 &&
        func_8004387C(arg0) == 0) {
        player_set_animation_shooting(arg0, 0xC);
        arg0[5] = 8;
        arg0[6] = 0;
    }
}
