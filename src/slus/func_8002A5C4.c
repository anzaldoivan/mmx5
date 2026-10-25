/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002943C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/stage_objects.c:start_screen_shake_x, AGPL-3.0; proven shared with X6 by exact signature 43e71a929bf8 (see THIRD_PARTY.md). */
#include "types.h"
extern X4_BackgroundObj D_8009A1F8[3];

void func_8002A5C4(s8 arg0, s8 arg1, s8 arg2) {
    D_8009A1F8[0].unk36 = arg0;
    D_8009A1F8[0].unk45 = arg1;
    D_8009A1F8[0].unk3E[0] = arg1;
    D_8009A1F8[0].unk3C = arg2;
    D_8009A1F8[0].unk3A = arg2;
    D_8009A1F8[0].unk34 |= 0x10;
}
