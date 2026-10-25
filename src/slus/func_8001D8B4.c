/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001C6C0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/memcard.c:func_8001CE84, AGPL-3.0; proven shared with X6 by exact signature e642975dc52e (see THIRD_PARTY.md). */
#include "types.h"

extern long format(u8*);
extern const MemcardPath D_800100B4;

s32 func_8001D8B4(s32 device_num) {
    MemcardPath buf = D_800100B4;

    buf.path[2] += device_num;
    return format(buf.path) ^ 1;
}
