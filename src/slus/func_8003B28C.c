/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003B954.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_enter.c:player_enter_beam_out, AGPL-3.0; proven shared with X6 by exact signature f6ae817e5d19 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/player.h"
#include "mmx5/sound.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define FIXED(x) ((s32)((x) * 0x10000))

void func_8003B28C(X4_Obj* self) {
    play_sound(1, 0xB, self);
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = FIXED(8);
    self->unk2C = 0;
    self->unk68 = 0;
    M2C_FIELD(self, s8*, 0x67) = 1;
    self->unk5 = PLAYER_BEAM_OUT;
    self->unk6 = 0;
}
