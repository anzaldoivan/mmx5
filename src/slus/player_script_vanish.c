/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037F70.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_script_vanish, AGPL-3.0; proven shared with X6 by exact signature 8c272e77d29e (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))

void player_script_vanish(X4_Obj* self) {
    if (func_80039ECC(self) == 0 && self->unk6 == 0) {
        ((void (*)())animate_object)(ANIMATED_OBJECT(self));
        if (M2C_FIELD(self, s8*, 0x46) == 0) {
            self->on_screen = 0;
            self->unk6++;
        }
    }
}
