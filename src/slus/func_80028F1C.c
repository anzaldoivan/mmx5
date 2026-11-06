#include "types.h"
#include "addr.h"

extern u16 D_80091D58;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;

void func_80028F1C(s32 idx, s32 wx, s32 wy) {
    s32 px;
    s32 py;
    u32 tx;
    u32 ty;
    u8 tile;

    px = (wx & 0xF0) / 16;
    py = (wy & 0xF0) / 16;
    tx = wx / 256;
    ty = wy / 256;
    if (tx >= D_800D1DBC || ty >= D_800D1DBD) {
        tile = 0;
    } else {
        tile = *(D_1F800004 + idx * D_80091D58 + D_800D1DBC * ty + tx);
    }
    ((u16*)(D_1F800008 + tile * 0x200 + py * 32))[px] = 0;
}
