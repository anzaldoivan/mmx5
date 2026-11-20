/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003D850.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_common.c:player_entry_beam_in, AGPL-3.0; proven shared with X6 by exact signature 6b996a39570c (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/player.h"
#include "mmx5/sound.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define FIXED(x) ((s32)((x) * 0x10000))

void func_8003D72C(X4_Obj* self) {
    func_8003B33C(self, 1);
    play_sound(1, 0xD, self);
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = FIXED(-8);
    self->unk2C = 0;
    M2C_FIELD(self, s8*, 0x67) = -1;
    self->unk5 = PLAYER_BEAM_IN;
}
