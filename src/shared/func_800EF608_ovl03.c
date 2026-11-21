#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

extern u8 D_800F959C_ovl03[];

void func_800EF608_ovl03(ObjEF608* arg0) {
    ((s32(*)())set_animation)(arg0, 1);
    arg0->unk80 = 5;
    arg0->unk20 = 0;
    arg0->unk54 = D_800F959C_ovl03;
    arg0->unk50 = D_800F959C_ovl03;
    arg0->unk6++;
}

/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC518.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_release, AGPL-3.0; proven shared with X6 by exact signature b8c90aca8278 (see THIRD_PARTY.md). */

void func_800EFD08_ovl03(X4_Obj*);

void func_800EF658_ovl03(X4_Obj* self) {
    ((void (*)())animate_object)(self);
    if (--self->unk80 == 0) {
        self->unk88 = 1;
        func_800EFD08_ovl03(self);
        self->unk80 = 13;
        self->unk6++;
    }
}
