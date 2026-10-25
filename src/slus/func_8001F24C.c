/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DF5C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/E47C.c:func_8001E638, AGPL-3.0; proven shared with X6 by exact signature 0bffad427ba7 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_800132F8(s32);

void func_8001F24C(struct X4_GameInfo* arg0) {
    M2C_FIELD(arg0, s16*, 0x4)--;
    if (M2C_FIELD(arg0, s16*, 0x4) == 0) {
        func_800132F8(8);
        arg0->mode++;
    }
}
