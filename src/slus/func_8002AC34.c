/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029AFC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/background.c:update_screen_shake_y, AGPL-3.0; proven shared with X6 by exact signature a0d9f0b7dd5c (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002AC34(X4_BackgroundObj* arg0) {
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
