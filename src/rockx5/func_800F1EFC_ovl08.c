/* Adapted from mmx6 @c1c892d src/shared/rock_05/func_800E9E80.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_56_jet_stingray.c:jet_stingray_vortex_finish, AGPL-3.0; proven shared with X6 by exact signature 5870cc71888c (see THIRD_PARTY.md). */
#include "types.h"

void func_800F1EFC_ovl08(X4_Obj* self) {
    if (--self->unk7C == 0) {
        self->unk5 = 2;
        self->unk6 = 0;
    }
}
