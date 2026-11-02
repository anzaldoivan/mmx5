#include "types.h"
#include "addr.h"

extern u16 D_80091D58;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;
extern u16 D_800A51A8[3][32][32];

static inline u8 func_80028608_tile(s32 idx, u32 tx, u32 ty) {
    if (tx >= D_800D1DBC || ty >= D_800D1DBD) {
        return 0;
    }
    return *(D_1F800004 + idx * D_80091D58 + D_800D1DBC * ty + tx);
}

void func_80028608(s32 idx, s32 x, s32 y) {
    u32 i;
    u32 tx;
    u32 ty;
    s32 col;
    s32 row;
    s32 px;
    s32 py;
    u8 tile;

    if (y >= 0) {
        tx = x / 256;
        ty = y / 256;
        col = (x % 512) / 16;
        row = (y % 512) / 16;
        px = col & 0xF;
        py = row & 0xF;
        tile = func_80028608_tile(idx, tx, ty);
        for (i = 0; i < 21; i++) {
            D_800A51A8[idx][row][col] =
                ((u16*)(D_1F800008 + tile * 0x200 + py * 32))[px];
            col++;
            col &= 0x1F;
            px++;
            if (px == 16) {
                px = 0;
                tx++;
                tile = func_80028608_tile(idx, tx, ty);
            }
        }
    }
}
