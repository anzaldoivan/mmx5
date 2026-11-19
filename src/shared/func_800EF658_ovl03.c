/* Shared body (DK-5), from the banked draft of func_800EF658_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC518.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_release, AGPL-3.0; proven shared with X6 by exact signature b8c90aca8278 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

void func_800EFD08_ovl03(X4_Obj*);

void DEDUP_NAME(X4_Obj* self) {
    ((void (*)())animate_object)(self);
    if (--self->unk80 == 0) {
        self->unk88 = 1;
        func_800EFD08_ovl03(self);
        self->unk80 = 13;
        self->unk6++;
    }
}
