/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029A6C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/background.c:update_screen_shake_x, AGPL-3.0; proven shared with X6 by exact signature 53e7a3858f9c (see THIRD_PARTY.md). */
#include "types.h"

void func_8002ABA4(X4_BackgroundObj* arg0) {
    if (--arg0->unk36 == 0) {
        arg0->unk34 &= ~0x10;
        return;
    }
    if (--arg0->unk3C == 0) {
        arg0->unk3E[0] ^= 0x80;
        arg0->unk3C = arg0->unk3A;
    }
    if (arg0->unk3E[0] >= 0) {
        arg0->x_pos.i.hi += arg0->unk45;
    }
}
