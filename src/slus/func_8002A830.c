/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800295E8.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/background.c:func_80027AFC, AGPL-3.0; proven shared with X6 by exact signature 3108906f66dd (see THIRD_PARTY.md). */
/* Y-axis twin of src/slus/func_8002A770.c (X5). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002A830(X4_BackgroundObj* arg0) {
    s16 delta;

    delta = arg0->y_pos.i.hi - arg0->unk18.i.hi;
    if (delta >= 0) {
        if (delta >= M2C_FIELD(arg0, s8*, 0x48)) {
            delta = M2C_FIELD(arg0, s8*, 0x48);
        }
        arg0->y_pos.i.hi = delta + arg0->unk18.i.hi;
    } else {
        if (delta < M2C_FIELD(arg0, s8*, 0x49)) {
            delta = M2C_FIELD(arg0, s8*, 0x49);
        }
        arg0->y_pos.i.hi = delta + arg0->unk18.i.hi;
    }
}
