/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC9D0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002DFF8(void* arg0, s32 arg1, s32 arg2);
void set_velocity_from_angle(void*, s32);
#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)

void func_800EFC38_ovl03(X4_Obj* self) {
    ((void (*)())animate_object)();
    if (--self->unk7C == 0) {
        self->unk5 = 8;
        self->unk6 = 0;
    }
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, s32*, 0x90) + 1;
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, u8*, 0x90) & 3;
    if (M2C_FIELD(self, u8*, 0x90) == 0) {
        set_velocity_from_angle(
            self, func_8002DFF8(self, g_Player_as_X4_Obj.x_pos.val,
                                g_Player_as_X4_Obj.y_pos.val) &
                      0xFF);
    }
    move_object(self);
}
#undef g_Player_as_X4_Obj
