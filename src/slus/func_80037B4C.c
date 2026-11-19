/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037F34.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_zero_ryuenjin_rise, AGPL-3.0; proven shared with X6 by exact signature dff51a405822 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80037B4C(X4_Obj* self) {
    if (func_80039ECC(self) == 0) {
        move_object(self);
        animate_object(self);
    }
}
