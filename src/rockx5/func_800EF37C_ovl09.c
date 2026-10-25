/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EB968.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_hover, AGPL-3.0; proven shared with X6 by exact signature 404516d3d41d (see THIRD_PARTY.md). */
#include "types.h"

extern void (*D_800FA778_ovl09[])(X4_Obj*);
void func_80017248(X4_Obj*);

void func_800EF37C_ovl09(X4_Obj* self) {
    func_80017248(self);
    D_800FA778_ovl09[self->unk6](self);
}
