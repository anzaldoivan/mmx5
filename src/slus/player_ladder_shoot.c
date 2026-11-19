/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EB730.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_ladder_shoot, AGPL-3.0; proven shared with X6 by exact signature 543816517dc7 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/player.h"
#include "mmx5/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
void func_8003B4CC(Ob6E78*, s32, s32);
s32 func_8003F094(Ob6E78*);
s32 func_80039E7C(Ob6E78* self);
void func_8003B148(Ob6E78* self);

void player_ladder_shoot(Ob6E78* self) {
    if ((func_80039E7C(self) == 0) && (func_8003F094(self) == 0)) {
        animate_object(ANIMATED_OBJECT(self));
        if (M2C_FIELD(self, u16*, 0x80) & PLAYER_INPUT_LEFT) {
            self->x15 = 0;
        }
        if (M2C_FIELD(self, u16*, 0x80) & PLAYER_INPUT_RIGHT) {
            self->x15 = 0x40;
        }
        if (self->x90 != 0) {
            func_8003B4CC(self, 0x20, 3);
            func_8003B148(self);
        }
    }
}
