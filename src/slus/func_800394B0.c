/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80039BC4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_check.c:player_check_dash_jump_walk, AGPL-3.0; proven shared with X6 by exact signature 67a670686326 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
s32 func_80039668(u8* arg0);
void func_8003A82C(u8* arg0);
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
#define M2C_UNK s32
s32 func_8003979C(X4_Obj*);
M2C_UNK func_8003A874(void*);
void func_8003A30C(X4_Obj*);

s32 func_800394B0(X4_Obj* self) {
    if (func_8003979C(self) != 0) {
        func_8003A30C(self);
        return 1;
    }
    if ((M2C_FIELD(self, u16*, 0x80) & PLAYER_INPUT_JUMP) != 0) {
        func_8003A874(self);
        return 1;
    }
    if (func_80039668(self) == 0) {
        return 0;
    }
    func_8003A82C(self);
    return 1;
}
