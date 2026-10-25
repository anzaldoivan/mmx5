/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004B4BC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_22_missile_smoke.c:missile_smoke_init, AGPL-3.0; proven shared with X6 by exact signature 350f949ca2ac (see THIRD_PARTY.md). */
#include "types.h"
void func_800F3658_ovl06(X4_Obj*);
s32 func_800171E8(void*, s32);

void func_800F3608_ovl06(X4_Obj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    if (arg0->unk2 != 0x10) {
        arg0->unk15 = 0;
        func_800F3658_ovl06(arg0);
    } else {
        arg0->unk16 = 2;
        func_800171E8(arg0, 0x25);
    }
}
