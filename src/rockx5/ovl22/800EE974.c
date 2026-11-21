#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8 D_800EEBC0_ovl22[];
extern u8 D_800EEC68_ovl22[];

void func_800EE974_ovl22(u8* obj) {
    s32 n;
    u8* t;
    u8* e;
    u8 b;

    *(u8**)(obj + 0x30) = D_800EEC68_ovl22;
    *(s8*)(obj + 0x14) = -1;
    obj[0x16] = 3;
    obj[0x15] = 0;
    *(s16*)(obj + 0x40) = 0x600;
    obj[4]++;
    *(volatile s32*)(obj + 0x3C) =
        (s32)D_1F800020.s32s +
        D_1F800020.s32s
            [0]; // !FAKE: volatile pair with the obj[2] read orders that load after this store (C0194)
    t = D_800EEBC0_ovl22;
    n = ((volatile u8*)obj)[2] *
        6; // !FAKE: volatile read keeps the load below the 0x3C store (C0194)
    e = n + t;
    b = e[5];
    *(s16*)(obj + 0x42) = (b & 0xF) | (((b >> 4) + 0x1E0) << 6);
    *(s32*)(obj + 8) = *(s16*)e << 16;
    *(s32*)(obj + 0xC) = *(s16*)(D_800EEBC0_ovl22 + n + 2) << 16;
    obj[0x47] = e[4];
    func_8002D89C(obj);
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_800D1F28[];
extern u8 D_800EEBC4_ovl22;
extern u8 D_800EEBCA_ovl22;
extern u8 D_800EEBD0_ovl22;
extern u8 D_800EEBD6_ovl22;

void func_800EEA40_ovl22(u8* obj) {
    u8* p;

    if (((s8*)obj)[2] == 6) {
        p = D_800D1F28;
        obj[0x16] = 2;
        *(s16*)(obj + 0xE) = (s8)(((s8*)p)[2] % 4) * 16 + 0x86;
        switch (((s8*)p)[2]) {
        case 0:
            obj[0x47] = D_800EEBC4_ovl22;
            break;
        case 1:
            obj[0x47] = D_800EEBCA_ovl22;
            break;
        case 2:
            obj[0x47] = D_800EEBD0_ovl22;
            break;
        default:
            obj[0x47] = D_800EEBD6_ovl22;
            break;
        }
    }
    if ((u8)(obj[2] - 4) < 2) {
        obj[3] = 0;
        if (D_8009A420_as_s32 & 0x10) {
            func_8002D89C(obj);
        }
    } else {
        obj[3] = 1;
        func_8002D89C(obj);
    }
}
