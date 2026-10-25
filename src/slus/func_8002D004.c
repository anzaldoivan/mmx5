/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002C2B8.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/objects.c:func_8002AB20, AGPL-3.0; proven shared with X6 by exact signature 7632243f87cd (see THIRD_PARTY.md). */
#include "types.h"
extern X4_BackgroundObj D_8009A1F8[3];

void func_8002D004() {
    s8 fill = 0;
    u32 i;
    for (i = 0; i < 3; i++) {
        s8* a0 = (u8*)&D_8009A1F8[i];
        s32 v1 = sizeof(X4_BackgroundObj) - 1;
        do {
            *a0++ = fill;
        } while (v1-- != 0);
        D_8009A1F8[i].pad0[2] = i;
    }
}
