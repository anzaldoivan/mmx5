#include "types.h"
#include "addr.h"

extern X4_BackgroundObj D_8009A1F8[3];
extern u16 D_80091D58;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;
extern u16 D_800A51A8[3][32][32];

static inline u8 func_800278E8_tile(u8 idx, u32 tx, u32 ty) {
    if (tx >= D_800D1DBC || ty >= D_800D1DBD) {
        return 0;
    }
    return *(D_1F800004 + idx * D_80091D58 + D_800D1DBC * ty + tx);
}

void func_800278E8(u8 idx) {
    X4_BackgroundObj* obj;
    s8 link;
    s32 x;
    s32 y;
    u32 tx;
    u32 ty;
    s32 px0;
    u32 tx0;
    s32 px;
    s32 sy;
    s32 py;
    s32 sx;
    s32 sx0;
    u8 tile;
    s8 i;
    s8 j;

    link = D_8009A1F8[idx].pad4C[6];
    obj = &D_8009A1F8[idx];
    if (link < 0) {
        x = obj->x_pos.i.hi / 16;
        y = obj->y_pos.i.hi / 16;
    } else {
        x = (obj->x_pos.i.hi + D_8009A1F8[link].x_pos.i.hi) / 16;
        y = (obj->y_pos.i.hi + D_8009A1F8[link].y_pos.i.hi) / 16;
    }
    tx = x / 16;
    tx0 = tx;
    ty = y / 16;
    sx0 = x & 0x1F;
    sy = y & 0x1F;
    px0 = x & 0xF;
    py = y & 0xF;
    for (i = 0; i < 17; i++) {
        px = px0;
        sx = sx0;
        tile = func_800278E8_tile(idx, tx, ty);
        for (j = 0; j < 22; j++) {
            D_800A51A8[idx][sy][sx] =
                ((u16*)(D_1F800008 + tile * 0x200 + py * 32))[px];
            sx++;
            px++;
            sx &= 0x1F;
            if (px == 16) {
                px = 0;
                tx++;
                tile = func_800278E8_tile(idx, tx, ty);
            }
        }
        tx = tx0;
        sy = (sy + 1) & 0x1F;
        py++;
        if (py == 16) {
            py = 0;
            ty++;
        }
    }
    D_8009A1F8[idx].pad4C[0] = 0;
}
