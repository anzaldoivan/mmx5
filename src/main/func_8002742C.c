/* Adapted from mmx6 @a8f96d1 refs/mmx6/src/SLUS_013.95/80026028.c:func_80026204, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

void func_8002742C(u16 color, u8* r, u8* g, u8* b) {
    u8 c;

    c = color & 0x1F;
    *r = (c << 3) + (c >> 2);
    c = (color >> 5) & 0x1F;
    *g = (c << 3) + (c >> 2);
    c = color >> 10;
    *b = (c << 3) + (c >> 2);
}
