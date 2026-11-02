#include "types.h"
#include "addr.h"

extern s32 func_80028FF0(s32 a, s32 x, s32 y);
extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
extern s16 D_800F5960_ovl05;
extern s16 D_800F5962_ovl05;

s32 func_800F29B4_ovl05(s16 x, s16 y) {
    u8* g = D_800D1C00;
    u8* p;
    s32 page;
    s32 cx;
    s32 cy;
    u8 v;

    if (((s8*)g)[0xF] != 0) {
        return 0;
    }
    if (x < D_800F5960_ovl05) {
        return 0;
    }
    if (D_800F5962_ovl05 < x) {
        return 0;
    }
    if (y < 0xA44) {
        return 0;
    }
    if (y >= 0xC40) {
        return 0;
    }
    p = D_8009A0A0;
    page = func_80028FF0(((s8*)p)[0x14], x >> 8, y >> 8);
    cx = (x & 0xF0) / 16;
    cy = (y & 0xF0) / 16;
    if (((u16(*)[16][16])D_1F800008)[page][cy][cx] & 0x8000) {
        return 0;
    }
    v = p[0x5C];
    ((s8*)p)[0x5C] = -0x80;
    *(s32*)(g + 0xB8) += v & 0x7F;
    return 1;
}
