/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800536D0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_wait, AGPL-3.0; proven shared with X6 by exact signature ec91c859e783 (see THIRD_PARTY.md). */
#include "types.h"

void func_80057130(X4_Obj* self) {
    if (--self->unk18.u.lo == 0) {
        self->unk5++;
    }
}
