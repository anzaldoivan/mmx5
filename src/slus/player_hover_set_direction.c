/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC478.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_hover_set_direction, AGPL-3.0; proven shared with X6 by exact signature 5022eaa90621 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

#define M2C_UNK s32
M2C_UNK player_set_animation_shooting(void*, M2C_UNK);
void player_hover_set_direction(X4_Obj* self, s32 direction) {
    if (direction > 0) {
        ((void (*)())player_set_animation_shooting)(self, 0x17);
        self->unk6 = 3;
    } else {
        ((void (*)())player_set_animation_shooting)(self, 0x19);
        self->unk6 = 5;
    }
}
