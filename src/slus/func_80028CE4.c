#include "types.h"
#include "addr.h"

extern u16 D_80091D58;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;
extern u16 D_800A51A8[3][32][32];

void func_80028CE4(s32 idx, s32 x, s32 y) {
    u32 tx;
    u32 ty;
    s32 col;
    s32 row;
    s32 px;
    s32 py;
    u8 tile;

    tx = x / 16;
    ty = y / 16;
    col = x % 32;
    row = y % 32;
    px = col & 0xF;
    py = row & 0xF;
    if (tx >= D_800D1DBC || ty >= D_800D1DBD) {
        tile = 0;
    } else {
        tile = *(D_1F800004 + idx * D_80091D58 + D_800D1DBC * ty + tx);
    }
    D_800A51A8[idx][row][col] =
        ((u16*)(D_1F800008 + tile * 0x200 + py * 32))[px];
}
