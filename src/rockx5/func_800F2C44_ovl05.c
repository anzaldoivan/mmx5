#include "types.h"
#include "addr.h"

extern s32 func_80028FF0(s32 a, s32 x, s32 y);
extern u8 D_8009A0B4;
extern s16 D_800F5960_ovl05;
extern s16 D_800F5962_ovl05;

static inline s32 func_800F2C44_ovl05_hit(u8* o, s16 x, s16 y) {
    s32 page;
    s32 cx;
    s32 cy;

    if (x >= D_800F5960_ovl05 && D_800F5962_ovl05 >= x && y >= 0xA44 &&
        y < 0xC40) {
        page = func_80028FF0((s8)D_8009A0B4, x >> 8, y >> 8);
        cx = (x & 0xF0) / 16;
        cy = (y & 0xF0) / 16;
        if (!(((u16(*)[16][16])D_1F800008)[page][cy][cx] & 0x8000)) {
            o[4] = 4;
            return 1;
        }
    }
    return 0;
}

void func_800F2C44_ovl05(u8* o) {
    u8* p;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    p = *(u8**)(o + 0x50);
    if (p == 0) {
        return;
    }
    if (o[0x15] != 0) {
        x0 = *(s16*)(o + 0xA) - ((s8*)p)[0];
        x1 = x0 - p[2] - 1;
    } else {
        x0 = *(s16*)(o + 0xA) + ((s8*)p)[0];
        x1 = p[2] + x0 + 1;
    }
    p = *(u8**)(o + 0x50);
    y0 = *(s16*)(o + 0xE) + ((s8*)p)[1];
    y1 = p[3] + y0 + 1;
    if (func_800F2C44_ovl05_hit(o, x0, y0)) {
        return;
    }
    if (func_800F2C44_ovl05_hit(o, x1, y0)) {
        return;
    }
    if (func_800F2C44_ovl05_hit(o, x0, y1)) {
        return;
    }
    func_800F2C44_ovl05_hit(o, x1, y1);
}
