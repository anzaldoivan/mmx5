#include "types.h"
#include "addr.h"

extern u16 D_80091D58;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;
extern u16 D_800A51A8[3][32][32];

void func_80028DFC(s32 idx, s32 x, s32 y, s32 wx, s32 wy) {
    s32 col;
    s32 row;
    s32 px;
    s32 py;
    u32 tx;
    u32 ty;
    u8 tile;

    col = (x & 0x1FF) / 16;
    row = (y & 0x1FF) / 16;
    px = (wx & 0xF0) / 16;
    py = (wy & 0xF0) / 16;
    tx = wx / 256;
    ty = wy / 256;
    if (tx >= D_800D1DBC || ty >= D_800D1DBD) {
        tile = 0;
    } else {
        tile = *(D_1F800004 + idx * D_80091D58 + D_800D1DBC * ty + tx);
    }
    D_800A51A8[idx][row][col] =
        ((u16*)(D_1F800008 + tile * 0x200 + py * 32))[px];
}
