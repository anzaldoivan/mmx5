/* Shared body (DK-5), from the banked draft of func_8004F5CC by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800496C0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_attach, AGPL-3.0; proven shared with X6 by exact signature 3cea93403e4f (see THIRD_PARTY.md). */
#include "types.h"
extern X4_S16Pair D_8007B5CC[2];

void DEDUP_NAME(X4_Obj* arg0, X4_Obj* arg1) {
    arg0->unk15 = arg1->unk15;
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi + D_8007B5CC[arg1->unk2].lo;
    } else {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - D_8007B5CC[arg1->unk2].lo;
    }
    arg0->y_pos.i.hi = arg1->y_pos.i.hi + D_8007B5CC[arg1->unk2].hi;
}
