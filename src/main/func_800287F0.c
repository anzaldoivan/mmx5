#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8* D_8007755C[][2];
extern u8* D_800EF330_ovl23[];
extern u16 g_tilemap_layer_stride;

void func_800288B4(s32);

void func_800287F0(void) {
    u8* p = g_playthrough_state.u;
    u8* src;
    u8* dst;
    u32 i;

    if ((s8)p[0xC] == 11) {
        src = D_800EF330_ovl23[(s8)p[0x1D]];
    } else {
        src = D_8007755C[(s8)p[0xC]][(s8)p[0xD]];
    }
    dst = D_1F800004;
    for (i = 0; i < g_tilemap_layer_stride * 3; i++) {
        *dst++ = *src++;
    }
    func_800288B4(-1);
}
