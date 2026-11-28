#include "types.h"
#include "mmx5/object.h"

extern void player_set_animation_shooting(u8* arg0, s32 arg1);

void func_8003A7E4(u8* arg0) {
    player_set_animation_shooting(arg0, 7);
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    move_object(arg0);
    arg0[5] = 3;
    arg0[6] = 0;
}
