/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003B954.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_enter.c:player_enter_beam_out, AGPL-3.0; proven shared with X6 by exact signature f6ae817e5d19 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define FIXED(x) ((s32)((x) * 0x10000))
enum X4_PlayerAction {
    PLAYER_BEAM_IN,
    PLAYER_BEAM_OUT,
    PLAYER_IDLE,
    PLAYER_WALK_START,
    PLAYER_WALK,
    PLAYER_SETTLE,
    PLAYER_JUMP,
    PLAYER_FALL,
    PLAYER_LAND,
    PLAYER_WALL_CLING,
    PLAYER_WALL_JUMP,
    PLAYER_WALL_SLIDE,
    PLAYER_DASH,
    PLAYER_AIR_DASH,
    PLAYER_LADDER_TRANSITION,
    PLAYER_LADDER_UP,
    PLAYER_LADDER_DOWN,
    PLAYER_HURT,
    PLAYER_RIDE,
    PLAYER_CAPSULE,
    PLAYER_SCRIPT_WAIT,
    PLAYER_SCRIPT_WALK,
    PLAYER_SCRIPT_VANISH,
    PLAYER_SCRIPT_JUMP,
    PLAYER_SCRIPT_VICTORY,
    PLAYER_STAGE_CLEAR,
    PLAYER_LADDER_SHOOT = 0x20,
    PLAYER_HOVER,
    PLAYER_NOVA_STRIKE,
    PLAYER_SOUL_BODY,
    PLAYER_SOUL_BODY_CLONE,
    PLAYER_SOUL_BODY_VANISH,
    PLAYER_WEAPON_POSE,
    PLAYER_RISING_FIRE,
    PLAYER_RISING_FIRE_CHARGED,
    PLAYER_ZERO_SABER = 0x30,
    PLAYER_ZERO_JUMP_SLASH,
    PLAYER_ZERO_FALL_SLASH,
    PLAYER_ZERO_LADDER_SLASH,
    PLAYER_ZERO_WALL_SLASH,
    PLAYER_ZERO_RAIJINGEKI,
    PLAYER_ZERO_HYOURETSUZAN,
    PLAYER_ZERO_SPIN_JUMP_SLASH,
    PLAYER_ZERO_SPIN_FALL_SLASH,
    PLAYER_ZERO_RYUENJIN,
    PLAYER_ZERO_RAKUHOUHA,
    PLAYER_ZERO_SHIPPUUGA,
};
s32 func_80016490(s32, s32, void*);

void func_8003B28C(X4_Obj* self) {
    func_80016490(1, 0xB, self);
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = FIXED(8);
    self->unk2C = 0;
    self->unk68 = 0;
    M2C_FIELD(self, s8*, 0x67) = 1;
    self->unk5 = PLAYER_BEAM_OUT;
    self->unk6 = 0;
}
