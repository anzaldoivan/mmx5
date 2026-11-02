#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8002385C(s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern s32 rsin(s32);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];
extern u8 D_800FB160_ovl52[];
extern u8 D_800FB560_ovl52[];
extern s32 D_800FB964_ovl52;

void func_800FA404_ovl52(u8* arg0) {
    s32 s;
    s32 v;
    u8* p;

    s = rsin(D_800FB964_ovl52);
    v = s * 0x10;
    D_800FB964_ovl52 = (D_800FB964_ovl52 + 0x10) & 0xFFF;
    if (v != 0) {
        v = s << 8;
    }
    p = D_8009A1F8;
    *(s32*)(p + 0xB4) = 0x02000000 - v;
    p[0xF4] = 1;
    if (D_80091C44 == 0) {
        func_8002C338(0x60, D_800FB160_ovl52, 0x10);
        func_8002C338(0x70, D_800FB560_ovl52, 0x10);
        *(s16*)(p + 0xA) = 0x1A0;
        p[0x3] = 1;
        *(s16*)(p + 0xE) = 8;
        *(s16*)(p + 0x5E) = 0x70;
        p[0x4C] = 1;
        p[0x57] = 1;
        *(s16*)(p + 0x62) = 8;
        p[0xA0] = 1;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x300;
        p[0xF4] = 1;
        func_80016490(2, 0x6C, 0);
        func_8002385C(0x4A, 0xFF, 0);
        arg0[1]++;
    }
}
