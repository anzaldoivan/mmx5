/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC1B4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_hover_forward_stop, AGPL-3.0; proven shared with X6 by exact signature c351fcf586bf (see THIRD_PARTY.md). */
#include "types.h"
void func_8003F2D8(u8* arg0, s32 arg1);
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
s32 func_80040B6C();

s32 func_80039AE0(void*);
#define M2C_UNK s32
M2C_UNK func_8003F294(void*, M2C_UNK);
s32 func_80040BBC(void*);
void func_80040C88(Ent448C* self, s32 direction);
void func_800409C4(Ent448C* self) {
    s32 action;

    if (func_80040B6C(self) == 0 && ((s32(*)())func_80039AE0)(self) == 0) {
        action = ((s32(*)())func_80040BBC)(self);
        if (action != PLAYER_BEAM_IN) {
            func_80040C88(self, action);
            return;
        }
        if (self->unk46 == 0) {
            ((void (*)())func_8003F294)(self, 0x16);
            self->unk6 = 2;
            return;
        }
        func_8003F2D8(self, 0x18);
    }
}
