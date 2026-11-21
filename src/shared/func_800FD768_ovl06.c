/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EA5F8.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_12_ride_dust.c:ride_dust_init, AGPL-3.0; proven shared with X6 by exact signature 6eac507027d5 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/graphics.h"
extern u8 D_800FF934_ovl06[];
extern u8 D_800FF940_ovl06[];

void func_800FD768_ovl06(X4_Obj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    arg0->unk16 = D_800FF940_ovl06[arg0->unk2];
    set_animation(arg0, D_800FF934_ovl06[arg0->unk2]);
}
