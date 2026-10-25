/* Adapted from mmx6 @c1c892d src/shared/rock_03/func_800EA910.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_57_frost_walrus.c:frost_walrus_blizzard_finish, AGPL-3.0; proven shared with X6 by exact signature ab19d9ae77b7 (see THIRD_PARTY.md). */
#include "types.h"

void func_800FCA74_ovl38(X4_Obj* self) {
    if (--self->unk7C == 0) {
        self->unk5 = 3;
        self->unk6 = 0;
    }
}
