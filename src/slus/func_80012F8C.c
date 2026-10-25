/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80013480.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/2824.c:func_800128EC, AGPL-3.0; proven shared with X6 by exact signature ea1f214c77bc (see THIRD_PARTY.md). */
#include "types.h"

void func_80012F8C(s32 arg0) {

    u16* temp_a0 = (arg0 << 7) + 0x801F8100;

    *temp_a0 |= 0x40;
}
