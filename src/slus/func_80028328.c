#include "types.h"
#include "addr.h"

extern X4_BackgroundObj D_8009A1F8[3];
extern u16 D_80091D58;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;
extern u16 D_800A51A8[3][32][32];

static inline u8 func_80028328_tile(s32 idx, u32 tx, u32 ty) {
    if (tx >= D_800D1DBC || ty >= D_800D1DBD) {
        return 0;
    }
    return *(D_1F800004 + idx * D_80091D58 + D_800D1DBC * ty + tx);
}

void func_80028328(s32 idx, s32 x, s32 y) {
    X4_BackgroundObj* base;
    X4_BackgroundObj* obj;
    X4_BackgroundObj* obj2;
    X4_BackgroundObj* base2;
    u32 n;
    u32 i;
    u32 t;
    u32 t2;
    u32 tx;
    u32 ty;
    s32 col;
    s32 row;
    s32 px;
    s32 py;
    u8 tile;
    u8 b1;
    u8 b2;
    u8 b3;

    if (x >= 0) {
        if (y < 0) {
            y = 0;
            n = 17;
        } else {
            n = 18;
        }
        tx = x / 256;
        ty = y / 256;
        col = (x % 512) / 16;
        row = (y % 512) / 16;
        py = row & 0xF;
        base = D_8009A1F8;
        obj = base + idx;
        b1 = obj->pad4C[1];
        px = col & 0xF;
        if (tx < b1) {
            t = tx + 1;
            b2 = obj->pad4C[2];
            tx = t + (b2 - b1);
            if (((b1 - 1) << 8) >= obj->x_pos.i.hi) {
                obj->x_pos.i.hi = b2 << 8;
                return;
            }
        }
        base2 = D_8009A1F8;
        obj2 = base2 + idx;
        b1 = obj2->pad4C[2];
        if (b1 < tx) {
            b3 = obj2->pad4C[1];
            t2 = tx - 1;
            tx = t2 - b1;
            tx += b3;
            if (obj2->x_pos.i.hi >= ((b1 + 1) << 8)) {
                obj2->x_pos.i.hi = b3 << 8;
                return;
            }
        }
        tile = func_80028328_tile(idx, tx, ty);
        for (i = 0; i < n; i++) {
            D_800A51A8[idx][row][col] =
                ((u16*)(D_1F800008 + tile * 0x200 + py * 32))[px];
            row++;
            row &= 0x1F;
            py++;
            if (py == 16) {
                py = 0;
                ty++;
                tile = func_80028328_tile(idx, tx, ty);
            }
        }
    }
}
