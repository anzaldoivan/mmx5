/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/cling/pressing_into_wall.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

// returns 1 when L/R is held into a touching climbable wall.
s32 is_pressing_into_wall(void* arg0) {
    u8* self = arg0;

    if (*(s8*)(self + 0xD3) != 0) {
        return 0;
    }
    if (*(s8*)(self + 0x4A) == 0) {
        return 0;
    }
    return (*(u16*)(self + 0x7C) & 3 & *(u8*)(self + 0x89)) != 0;
}
