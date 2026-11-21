#include "types.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029A6C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/background.c:update_screen_shake_x, AGPL-3.0; proven shared with X6 by exact signature 53e7a3858f9c (see THIRD_PARTY.md). */

void update_screen_shake_x(X4_BackgroundObj* arg0) {
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

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029AFC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/background.c:update_screen_shake_y, AGPL-3.0; proven shared with X6 by exact signature a0d9f0b7dd5c (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void update_screen_shake_y(X4_BackgroundObj* arg0) {
    if (--M2C_FIELD(arg0, s8*, 0x37) == 0) {
        arg0->unk34 &= 0xFFFE;
        return;
    }
    if (--M2C_FIELD(arg0, s8*, 0x3D) == 0) {
        arg0->unk3E[1] ^= 0x80;
        M2C_FIELD(arg0, s8*, 0x3D) = M2C_FIELD(arg0, s8*, 0x3B);
    }
    if (arg0->unk3E[1] >= 0) {
        arg0->y_pos.i.hi += M2C_FIELD(arg0, s8*, 0x46);
    }
}
