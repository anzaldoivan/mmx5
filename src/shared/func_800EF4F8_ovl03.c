/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC3B8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

s32 func_8002DFF8(void* arg0, s32 arg1, s32 arg2);
void set_velocity_from_angle(void*, s32);
#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)

void func_800EF4F8_ovl03(X4_Obj* self) {
    X4_Obj* pl;
    s32 v;
    s32 dx;

    animate_object();
    move_object(self);
    pl = &g_Player_as_X4_Obj;
    set_velocity_from_angle(
        self,
        func_8002DFF8(self, pl->x_pos.val, pl->y_pos.val + 0xFFB00000) & 0xFF);
    v = self->x_vel.val + self->x_vel.val / 2;
    self->x_vel.val = v;
    v = (v < 0 ? -v : v) + 0x20000;
    dx = pl->x_pos.val - self->x_pos.val;
    if (dx < 0) {
        dx = self->x_pos.val - pl->x_pos.val;
    }
    if (v >= dx || --self->unk7C == 0) {
        self->unk5 = 3;
        self->unk6 = 0;
    }
}
#undef g_Player_as_X4_Obj
