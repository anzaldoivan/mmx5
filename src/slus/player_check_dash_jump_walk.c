/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80039BC4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_check.c:player_check_dash_jump_walk, AGPL-3.0; proven shared with X6 by exact signature 67a670686326 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/player.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
s32 func_80039668(u8* arg0);
void func_8003A82C(u8* arg0);
#define M2C_UNK s32
s32 func_8003979C(X4_Obj*);
M2C_UNK func_8003A874(void*);
void func_8003A30C(X4_Obj*);

s32 player_check_dash_jump_walk(X4_Obj* self) {
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
