#include "types.h"

void func_800F4D50_ovl24(u8* arg0, s16 arg1, s16 arg2, u8 arg3);
extern u8 D_800D1C00[];
extern s32 D_800F59C8_ovl24[];
extern s32 D_800F59D4_ovl24[];
extern s32 D_800F59E0_ovl24[];
extern s16 D_800F59EC_ovl24[];
extern s16 D_800F59F4_ovl24[];
extern s16 D_800F59FC_ovl24[][2];

static inline s16 func_800F45D4_ovl24_rate32(s16 n, s32 v, s32* t) {
    if (t[0] >= v) {
        return n + 8;
    } else if (t[1] >= v) {
        return n + 4;
    } else if (t[2] >= v) {
        return n + 2;
    } else {
        return n + 1;
    }
}

static inline s32 func_800F45D4_ovl24_rate16(s16 n, s16 v, s16* t) {
    if (t[0] >= v) {
        return (s16)(n + 8);
    } else if (t[1] >= v) {
        return (s16)(n + 4);
    } else if (t[2] >= v) {
        return (s16)(n + 2);
    } else {
        return (s16)(n + 1);
    }
}

static inline s16 func_800F45D4_ovl24_rate16r(s16 n, s16 v, s16* t) {
    if (v >= t[0]) {
        return n + 8;
    } else if (v >= t[1]) {
        return n + 4;
    } else if (v >= t[2]) {
        return n + 2;
    } else {
        return n + 1;
    }
}

static inline s32 func_800F45D4_ovl24_rating(s32 a, s32 b, s32 c, s16 d,
                                             s16 e) {
    s16 n;

    if (D_800F59C8_ovl24[0] >= a) {
        n = 8;
    } else if (D_800F59C8_ovl24[1] >= a) {
        n = 4;
    } else if (D_800F59C8_ovl24[2] >= a) {
        n = 2;
    } else {
        n = 1;
    }
    n = func_800F45D4_ovl24_rate32(n, b, D_800F59D4_ovl24);
    n = func_800F45D4_ovl24_rate32(n, c, D_800F59E0_ovl24);
    n = func_800F45D4_ovl24_rate16r(n, d, D_800F59EC_ovl24);
    return func_800F45D4_ovl24_rate16(n, e, D_800F59F4_ovl24);
}

void func_800F45D4_ovl24(u8* arg0) {
    u8* p = D_800D1C00;
    u8 lvl = (D_800D1C00 + *(s8*)(p + 0x44))[0xAA];
    s32 a = *(s32*)(D_800D1C00 + 0xB0);
    s32 b = *(s32*)(D_800D1C00 + 0xB4);
    s32 c = *(s32*)(D_800D1C00 + 0xB8);
    s16 d = *(s16*)(D_800D1C00 + 0xBC);
    s16 e = *(s16*)(D_800D1C00 + 0xBE);
    s32 m;

    m = func_800F45D4_ovl24_rating(a, b, c, d, e);
    if (D_800F59FC_ovl24[lvl][0] >= m) {
        if (lvl < 7) {
            lvl++;
        }
    } else if (D_800F59FC_ovl24[lvl][1] < m) {
        if (lvl != 0) {
            lvl--;
        }
    }
    {
        u8* q = D_800D1C00;
        (D_800D1C00 + *(s8*)(q + 0x44))[0xAA] = lvl;
    }
    func_800F4D50_ovl24(arg0, 0, 0, lvl + 10);
    arg0[4] = 2;
}
