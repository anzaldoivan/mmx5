/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC8C0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_dive_fall, AGPL-3.0; proven shared with X6 by exact signature 551fe75c1ef0 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
#define MOVING_OBJECT(object) ((X4_Obj*)(object))

void func_800EFA00_ovl03(X4_Obj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    ((void (*)())move_object)(MOVING_OBJECT(self));
    self->y_vel.val += 0x100;
}
