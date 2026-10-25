/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80017E24.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_800160AC, AGPL-3.0; proven shared with X6 by exact signature 8cc804b315e5 (see THIRD_PARTY.md). */
#include "types.h"
#define SP(offset) (0x1F800000 + (offset))
#define SP_BG_TILE_ATTRS (*(u32**)SP(0x00C))
#define SP_BG_TILE_PIXELS (*(u16**)SP(0x008))
extern u16* D_800A51A0;

void func_80017668(void) {
    u16* src = D_800A51A0;
    u16* dst = SP_BG_TILE_PIXELS;
    s32 count = (u32)((u8*)SP_BG_TILE_ATTRS - (u8*)dst) >> 1;

    while (count > 0) {
        *dst++ = *src++;
        count--;
    }
}
