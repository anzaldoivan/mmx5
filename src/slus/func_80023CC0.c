#include "types.h"

extern void func_8002414C(u8*);
extern s32 func_8002C338(s32, void*, s32);
extern u8 D_800C9320;
extern u8* D_800E8514;
extern u8* D_800E8518;
extern u8* D_800E851C;
extern u8* D_800E8520;
extern u8* D_800E8524;
extern u8* D_800E8528;
extern u8* D_800E852C;
extern s16 D_800E8538;
extern u8 D_800E8540[];
extern u8 D_800E8580;
extern u8 D_800E8581;
extern u8 D_800D1C00[];

static inline void func_80023CC0_clr(u8** pp) {
    u8* p = *pp;

    if (p != 0 && ((s8*)p)[1] == 0x16) {
        p[0] = 0;
        (*pp)[3] = 0;
    }
}

void func_80023CC0(u8* o) {
    switch (o[0xD]) {
    case 0:
        if (--*(s16*)(o + 0xA) == 0) {
            o[0xC] = 1;
            o[0xD] = 1;
        }
        break;
    case 1:
        func_8002414C(o);
        break;
    case 2:
        if (D_800C9320 != 0) {
            o[0xF] = 0;
        }
        if (--*(s16*)(o + 0xA) == 0) {
            o[0xD] = 1;
        }
        break;
    case 3:
        if (D_800C9320 != 0) {
            func_80023CC0_clr(&D_800E851C);
            if (*(u16*)(o + 0x4) & 0x8000) {
                func_80023CC0_clr(&D_800E8518);
                func_80023CC0_clr(&D_800E8524);
                func_80023CC0_clr(&D_800E852C);
                func_80023CC0_clr(&D_800E8520);
                func_80023CC0_clr(&D_800E8528);
                *(s16*)(o + 0xA) = 0x32;
                o[0xD] = 4;
                o[0xC] = 0x80;
            } else {
                D_800E8538 = 0;
                o[0xC] = 1;
                *(s16*)(o + 0x6) = -0x5C;
                *(s16*)(o + 0x8) = 0x1D;
                o[0xE]++;
                func_8002414C(o);
            }
        }
        break;
    case 4:
        if (--*(s16*)(o + 0xA) == 0) {
            if ((s8)D_800D1C00[0xC] != 0xD) {
                func_8002C338(0x15, D_800E8540, 2);
            } else {
                func_8002C338(0x3E, D_800E8540, 2);
            }
            D_800D1C00[0x24] = D_800E8581;
            D_800D1C00[0x1F] = D_800E8580;
            func_80023CC0_clr(&D_800E8514);
            func_80023CC0_clr(&D_800E8518);
            func_80023CC0_clr(&D_800E851C);
            func_80023CC0_clr(&D_800E8524);
            func_80023CC0_clr(&D_800E8520);
            func_80023CC0_clr(&D_800E852C);
            func_80023CC0_clr(&D_800E8528);
            o[0xE] = 0;
            o[0xD] = 5;
            o[0xC] = 0;
        }
        break;
    case 5:
        break;
    case 6:
        if (--*(s16*)(o + 0xA) == 0) {
            o[0xC] = 0;
        }
        break;
    }
}
