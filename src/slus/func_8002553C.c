#include "types.h"
#include "addr.h"

extern X4_BackgroundObj D_8009A1F8[3];
extern u8 D_80071374[];
extern X4_P_TAG* D_80091C50[2][4][8];
extern s32 GetTPage(s32 tp, s32 abr, s32 x, s32 y);

void func_8002553C(u8* a0) {
    s32 code;
    s16 x;
    s16 y;
    u8* poly;
    u8* tpage;
    u8* p;
    s32 layer;
    s32 hi;
    s32 lo;
    s32 idx;

    if (D_1F800124 < 1000) {
        D_1F800124++;
        idx = ((s8*)a0)[0x37];
        if (idx < 0) {
            x = *(s16*)(a0 + 0xA);
            y = *(s16*)(a0 + 0xE);
        } else {
            x = *(s16*)(a0 + 0xA) - D_8009A1F8[idx].x_pos.i.hi;
            y = *(s16*)(a0 + 0xE) - D_8009A1F8[idx].y_pos.i.hi;
        }
        tpage = D_1F800104;
        poly = D_1F800100;
        poly[3] = 8;
        poly[7] = 0x38;
        code = a0[0] & 0x10;
        if (code != 0) {
            code = 0x3A;
        } else {
            code = 0x38;
        }
        poly[7] = code;
        *(s16*)(poly + 0x8) = x + *(s16*)(a0 + 0x16);
        *(s16*)(poly + 0xA) = y + *(s16*)(a0 + 0x1A);
        *(s16*)(poly + 0x10) = x + *(s16*)(a0 + 0x1E);
        *(s16*)(poly + 0x12) = y + *(s16*)(a0 + 0x22);
        *(s16*)(poly + 0x18) = x + *(s16*)(a0 + 0x2E);
        *(s16*)(poly + 0x1A) = y + *(s16*)(a0 + 0x32);
        *(s16*)(poly + 0x20) = x + *(s16*)(a0 + 0x26);
        *(s16*)(poly + 0x22) = y + *(s16*)(a0 + 0x2A);
        p = &D_80071374[*(u16*)(a0 + 0x34) * 12];
        poly[4] = *p++;
        poly[5] = *p++;
        poly[6] = *p++;
        poly[0xC] = *p++;
        poly[0xD] = *p++;
        poly[0xE] = *p++;
        poly[0x1C] = *p++;
        poly[0x1D] = *p++;
        poly[0x1E] = *p++;
        poly[0x14] = *p++;
        poly[0x15] = *p++;
        poly[0x16] = *p++;
        tpage[3] = 1;
        *(u32*)(tpage + 4) =
            (GetTPage(0, ((s8*)a0)[0] >> 5, 0, 0) & 0x9FF) | 0xE1000000;
        layer = a0[0x36];
        hi = (u8)layer >> 4;
        lo = layer & 0xF;
        D_80091C50[D_1F800000][hi][lo]->tag =
            (D_80091C50[D_1F800000][hi][lo]->tag & 0xFF000000) |
            ((u32)tpage & 0xFFFFFF);
        *(u32*)tpage = (*(u32*)tpage & 0xFF000000) | ((u32)poly & 0xFFFFFF);
        D_80091C50[D_1F800000][hi][lo] = (X4_P_TAG*)poly;
        D_1F800100 += 0x28;
        D_1F800104 += 8;
    }
}
