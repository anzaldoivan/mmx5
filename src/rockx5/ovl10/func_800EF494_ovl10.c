/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800E9D20.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_07_water_wake.c:water_wake_player_moving, AGPL-3.0; proven shared with X6 by exact signature 98768ef976bc (see THIRD_PARTY.md). */
#include "types.h"
extern u8 D_800FAB50_ovl10[9][16];
extern u8 D_800FABE0_ovl10[9][16];

s32 func_800EF494_ovl10(X4_Obj* arg0) {
    u8 state;

    if (arg0->unk2 == 0) {
        state = D_800FAB50_ovl10[0][arg0->unk17];
    } else {
        state = D_800FABE0_ovl10[0][arg0->unk17];
    }

    return state == 2;
}
