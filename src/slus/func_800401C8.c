/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EB730.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_ladder_shoot, AGPL-3.0; proven shared with X6 by exact signature 543816517dc7 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
enum X4_PlayerInput {
    PLAYER_INPUT_RIGHT = 0x1,
    PLAYER_INPUT_LEFT = 0x2,
    PLAYER_INPUT_UP = 0x4,
    PLAYER_INPUT_DOWN = 0x8,
    PLAYER_INPUT_SHOOT = 0x10,
    PLAYER_INPUT_SPECIAL = 0x20,
    PLAYER_INPUT_GIGA = 0x40,
    PLAYER_INPUT_JUMP = 0x80,
    PLAYER_INPUT_DASH = 0x100,
    PLAYER_INPUT_NEXT_WEAPON = 0x200,
    PLAYER_INPUT_PREVIOUS_WEAPON = 0x400,
};
void func_8003B4CC(Ob6E78*, s32, s32);
void func_80017248(X4_Obj*);
s32 func_8003F094(Ob6E78*);
s32 func_80039E7C(Ob6E78* self);
void func_8003B148(Ob6E78* self);

void func_800401C8(Ob6E78* self) {
    if ((func_80039E7C(self) == 0) && (func_8003F094(self) == 0)) {
        func_80017248(ANIMATED_OBJECT(self));
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
