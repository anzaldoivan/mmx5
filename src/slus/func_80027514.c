#include "types.h"
#include "addr.h"

extern u16 D_80091D58;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;

static inline u8 func_80027514_tile(s32 idx, u32 tx, u32 ty) {
    if (tx >= D_800D1DBC || ty >= D_800D1DBD) {
        return 0;
    }
    return *(D_1F800004 + idx * D_80091D58 + D_800D1DBC * ty + tx);
}

void func_80027514(s32 idx, s32 dx, s32 dy, s32 sx, s32 sy) {
    s32 spx;
    s32 spy;
    s32 dpx;
    s32 dpy;
    u8 src;
    u8 dst;

    spx = (sx & 0xF0) / 16;
    spy = (sy & 0xF0) / 16;
    dpx = (dx & 0xF0) / 16;
    dpy = (dy & 0xF0) / 16;
    src = func_80027514_tile(idx, sx / 256, sy / 256);
    dst = func_80027514_tile(idx, dx / 256, dy / 256);
    ((u16*)(D_1F800008 + dst * 0x200 + dpy * 32))[dpx] =
        ((u16*)(D_1F800008 + src * 0x200 + spy * 32))[spx];
}
