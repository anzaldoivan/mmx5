/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/cling/pressing_into_wall.c, AGPL-3.0 (THIRD_PARTY.md). */
// prog SLUS_013.95 | system cling | range 0x8003A394-0x8003A3D8
#include "types.h"

// 0x8003A394 func_80039BA8: returns 1 when L/R is held into a touching climbable wall.
// basis: xref derived.tsv:101; xref:callee=try_enter_wall_cling
// callers: handle_slide_down, try_enter_wall_cling
s32 func_80039BA8(void* arg0) {
    u8* self = arg0;

    if (*(s8*)(self + 0xD3) != 0) {
        return 0;
    }
    if (*(s8*)(self + 0x4A) == 0) {
        return 0;
    }
    return (*(u16*)(self + 0x7C) & 3 & *(u8*)(self + 0x89)) != 0;
}
