/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC2D0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_hover_back_stop, AGPL-3.0; proven shared with X6 by exact signature b28126054f46 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/player.h"

s32 try_enter_wall_cling(void*);
#define M2C_UNK s32
M2C_UNK player_set_animation_shooting(void*, M2C_UNK);
s32 func_80040BBC(void*);
void player_hover_back_stop(Ent448C* self) {
    s32 action;

    if (func_80040B6C(self) == 0 &&
        ((s32(*)())try_enter_wall_cling)(self) == 0) {
        action = ((s32(*)())func_80040BBC)(self);
        if (action != PLAYER_BEAM_IN) {
            player_hover_set_direction(self, action);
            return;
        }
        if (self->unk46 == 0) {
            ((void (*)())player_set_animation_shooting)(self, 0x16);
            self->unk6 = 2;
            return;
        }
        func_8003F2D8(self, 0x1A);
    }
}
