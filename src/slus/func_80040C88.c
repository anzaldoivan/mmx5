/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC478.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_hover_set_direction, AGPL-3.0; proven shared with X6 by exact signature 5022eaa90621 (see THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
M2C_UNK func_8003F294(void*, M2C_UNK);
void func_80040C88(X4_Obj* self, s32 direction) {
    if (direction > 0) {
        ((void (*)())func_8003F294)(self, 0x17);
        self->unk6 = 3;
    } else {
        ((void (*)())func_8003F294)(self, 0x19);
        self->unk6 = 5;
    }
}
