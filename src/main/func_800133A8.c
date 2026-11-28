/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/8001344C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @4e16dfc src/main/2824.c:func_800128EC, AGPL-3.0; proven shared with X6 by exact signature ea1f214c77bc (see THIRD_PARTY.md). */
#include "types.h"

void func_800133A8(s32* src, s32* dst, s32 n) {
    do {
        s32 a = src[0];
        s32 b = src[1];
        // !FAKE: target keeps the third word in t0
        register s32 c asm("$8") = src[2];
        // !FAKE: target keeps the fourth word in t1
        register s32 d asm("$9") = src[3];
        dst[0] = a;
        dst[1] = b;
        dst[2] = c;
        dst[3] = d;
        do {
            src += 4;
        } while (0); // !FAKE: fence keeps the src bump before n-- (schedule)
        n--;
        dst += 4;
    } while (n != 0);
}
