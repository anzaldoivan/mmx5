#include "types.h"
#include "addr.h"

extern u16 D_80070B18[][4];
extern X4_P_TAG* D_80091C50[2][4][8];
extern void func_8002742C(u16 c, u8* r, u8* g, u8* b);
extern u8 func_80027474(u8 from, u8 to, u32 den, u32 t);

void func_80018ED0(s16 x0, s16 y0, s16 x1, s16 y1, s16 w, s32 idx, s32 den,
                   s32 t) {
    u8* poly;
    u8* tpage;
    u8* ot;
    s32 i;
    s32 j;
    X4_P_TAG* tag;

    tpage = D_1F800104;
    poly = D_1F800100;
    poly[3] = 8;
    poly[7] = 0x38;
    *(s16*)(poly + 0x8) = x0;
    *(s16*)(poly + 0xA) = y0;
    *(s16*)(poly + 0x10) = x0 + w;
    *(s16*)(poly + 0x12) = y0;
    *(s16*)(poly + 0x18) = x1;
    *(s16*)(poly + 0x1A) = y1;
    *(s16*)(poly + 0x20) = x1 + w;
    *(s16*)(poly + 0x22) = y1;
    func_8002742C(D_80070B18[idx][0], poly + 4, poly + 5, poly + 6);
    func_8002742C(D_80070B18[idx][1], poly + 0xC, poly + 0xD, poly + 0xE);
    func_8002742C(D_80070B18[idx][2], poly + 0x14, poly + 0x15, poly + 0x16);
    func_8002742C(D_80070B18[idx][3], poly + 0x1C, poly + 0x1D, poly + 0x1E);
    poly[0xC] = func_80027474(poly[0xC], poly[4], den, t);
    poly[0xD] = func_80027474(poly[0xD], poly[5], den, t);
    poly[0xE] = func_80027474(poly[0xE], poly[6], den, t);
    poly[0x1C] = func_80027474(poly[0x1C], poly[0x14], den, t);
    poly[0x1D] = func_80027474(poly[0x1D], poly[0x15], den, t);
    poly[0x1E] = func_80027474(poly[0x1E], poly[0x16], den, t);
    tpage[3] = 1;
    *(u32*)(tpage + 4) = 0xE1000000;
    ot = (u8*)D_80091C50;
    i = (D_1F800000 << 7) + 0x14;
    tag = *(X4_P_TAG**)(ot + i);
    tag->tag = (tag->tag & 0xFF000000) | ((u32)tpage & 0xFFFFFF);
    *(u32*)tpage = (*(u32*)tpage & 0xFF000000) | ((u32)poly & 0xFFFFFF);
    j = (D_1F800000 << 7) + 0x14;
    *(X4_P_TAG**)(ot + j) = (X4_P_TAG*)poly;
    D_1F800100 += 0x28;
    D_1F800104 += 8;
}
