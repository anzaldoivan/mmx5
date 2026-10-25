/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800134A4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/2824.c:func_80012910, AGPL-3.0; proven shared with X6 by exact signature 56ff4cada450 (see THIRD_PARTY.md). */
#include "types.h"

void func_80012FB0(s32 arg0) {

    u16* temp_a0 = (arg0 << 7) + 0x801F8100;

    *temp_a0 &= ~0x40;
}
