#include "types.h"

extern void LoadImage(void*, void*);
extern s32 DrawSync(s32);

void func_8001B1A8(u32* src, s32 x, s32 y, u32 size, s32 h, s32 wide) {
    s16 rect[4];
    u32 i;
    u32 stride;
    s32 w;

    w = 16;
    if (wide != 0) {
        w = 24;
    }
    stride = (u32)(w * h) >> 1;
    rect[0] = x;
    rect[1] = y;
    rect[2] = w;
    rect[3] = h;
    for (i = 0; i < size >> 4; i++) {
        LoadImage(rect, src);
        DrawSync(0);
        src += stride;
        rect[0] += w;
    }
}
