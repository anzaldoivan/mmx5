/* Adapted from mmx6 @c1c892d src/shared/rock_10/func_800EA068.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/misc/misc_00_static_sprite.c:spawn_common_effect, AGPL-3.0; proven shared with X6 by exact signature 1d1542c14e9b (see THIRD_PARTY.md). */
#include "types.h"
#define NULL ((void*)0)
X4_Obj* func_8002D27C(void);

void func_800EEFCC_ovl10(X4_Obj* self, s8 arg1) {
    X4_Obj* misc;

    misc = func_8002D27C();
    if (misc != NULL) {
        misc->active = 0x41;
        misc->id = 1;
        misc->unk2 = arg1;
        misc->unk15 = self->unk15;
        misc->x_pos = self->x_pos;
        misc->y_pos = self->y_pos;
    }
}
