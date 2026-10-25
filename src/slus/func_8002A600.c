/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029478.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/stage_objects.c:start_screen_shake_y, AGPL-3.0; proven shared with X6 by exact signature 503943cdb46f (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern X4_BackgroundObj D_8009A1F8[3];

void func_8002A600(s8 arg0, s8 arg1, s8 arg2) {
    D_8009A1F8[0].unk37 = arg0;
    M2C_FIELD(&D_8009A1F8[0], s8*, 0x46) = arg1;
    D_8009A1F8[0].unk3E[1] = arg1;
    M2C_FIELD(&D_8009A1F8[0], s8*, 0x3D) = arg2;
    M2C_FIELD(&D_8009A1F8[0], s8*, 0x3B) = arg2;
    D_8009A1F8[0].unk34 |= 1;
}
