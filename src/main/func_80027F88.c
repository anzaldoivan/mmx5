#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u32* D_80091D60[2][102];
extern u16 D_800A51A8[3][32][32];

void func_80027F88(s32 arg0) {
    u8* base;
    u8* obj;
    u8* par;
    u8* out;
    s32 x;
    s32 y;
    s32 col0;
    s32 col;
    s32 row;
    s16 px0;
    s16 px;
    s16 py;
    u32 i;
    u32 j;
    u32 ent;
    u32 hi;
    u16 tile;
    s32 k;
    u32** slot;
    u32* p;
    s32 bank;
    u8* tbl;
    u32 v;
    u32 h;
    u32 c;
    u32 d;

    base = D_8009A1F8.u;
    obj = base + arg0 * 0x54;
    out = D_1F800108;
    bank = D_1F800000;
    if (*(s8*)(obj + 0x52) < 0) {
        x = *(s16*)(obj + 0xA);
        y = *(s16*)(obj + 0xE);
    } else {
        par = base + *(s8*)(obj + 0x52) * 0x54;
        x = *(s16*)(obj + 0xA) + *(s16*)(par + 0xA);
        y = *(s16*)(obj + 0xE) + *(s16*)(par + 0xE);
    }
    col0 = (x / 16) & 0x1F;
    px0 = -(x & 0xF);
    row = (y / 16) & 0x1F;
    py = -(y & 0xF);
    for (i = 0; i < 16; i++) {
        col = col0;
        px = px0;
        for (j = 0; j < 21; j++) {
            tile = D_800A51A8[arg0][row][col];
            if (tile != 0) {
                if (D_1F80011C >= 1000) {
                    return;
                }
                D_1F80011C++;
                ent = ((u32*)D_1F80000C)[tile & 0x3FFF];
                hi = (ent & 0xFF000000) >> 24;
                if (hi != 0xFF) {
                    v = ((ent & 0xF000) >> 6) + 0x7900;
                    v += (hi & 0x40) << 4;
                    *(u16*)(out + 0xE) = v | ((ent & 0xF00) >> 8);
                    if (tile & 0x4000) {
                        out[7] |= 2;
                    } else {
                        out[7] &= 0xFD;
                    }
                    k = arg0;
                    c = (ent >> 12) & 0xF0;
                    d = (ent >> 16) & 0xF0;
                    do {
                    } while (
                        0); // !FAKE: fence keeps both bytes computed before the 0xC store
                    out[0xC] = c;
                    *(s16*)(out + 8) = px;
                    *(s16*)(out + 0xA) = py;
                    out[0xD] = d;
                    if (tile & 0x8000) {
                        k += 3;
                    }
                    tbl = (u8*)D_80091D60;
                    h = hi & 0x3F;
                    slot = (u32**)(tbl + ((k * 17 + h) * 4 + bank * 408));
                    p = *slot;
                    *p = (*p & 0xFF000000) | ((u32)out & 0xFFFFFF);
                    *slot = (u32*)out;
                    out += 0x10;
                }
            }
            px += 16;
            col++;
            col &= 0x1F;
        }
        py += 16;
        row++;
        row &= 0x1F;
    }
    D_1F800108 = out;
}
