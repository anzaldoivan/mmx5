#include "types.h"

void func_800F4D50_ovl24(u8* arg0, s16 arg1, s16 arg2, u8 arg3);
extern s32 D_800D1CB0;
extern s16 D_800F5954_ovl24[];

void func_800F3EEC_ovl24(u8* arg0) {
    s32 t;
    s32 min;
    s32 sec;
    s32 frm;
    s32 hi;
    s32 lo;

    t = D_800D1CB0;
    func_800F4D50_ovl24(arg0, 0, 0, 0x1B);
    func_800F4D50_ovl24(arg0, 0, 0, 0x1C);
    if (t > 359999) {
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[0], D_800F5954_ovl24[1],
                            0x89);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[2], D_800F5954_ovl24[3],
                            0x89);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[4], D_800F5954_ovl24[5],
                            0x85);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[6], D_800F5954_ovl24[7],
                            0x89);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[8], D_800F5954_ovl24[9],
                            0x89);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[10], D_800F5954_ovl24[11],
                            0x89);
    } else if (t <= 0) {
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[0], D_800F5954_ovl24[1],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[2], D_800F5954_ovl24[3],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[4], D_800F5954_ovl24[5],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[6], D_800F5954_ovl24[7],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[8], D_800F5954_ovl24[9],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[10], D_800F5954_ovl24[11],
                            0x80);
    } else {
        min = t / 3600;
        sec = t / 60;
        sec -= min * 60;
        frm = t / 60;
        frm = t - frm * 60;
        if (min >= 100) {
            min = 99;
        }
        if (min != 0) {
            hi = min / 10;
            lo = min % 10;
        } else {
            hi = 0;
            lo = 0;
        }
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[0], D_800F5954_ovl24[1],
                            hi + 0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[2], D_800F5954_ovl24[3],
                            lo + 0x80);
        if (sec != 0) {
            hi = sec / 10;
            lo = sec % 10;
        } else {
            hi = 0;
            lo = 0;
        }
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[4], D_800F5954_ovl24[5],
                            hi + 0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[6], D_800F5954_ovl24[7],
                            lo + 0x80);
        if (frm != 0) {
            frm = frm * 100 / 60;
            hi = frm / 10;
            lo = frm % 10;
        } else {
            hi = 0;
            lo = 0;
        }
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[8], D_800F5954_ovl24[9],
                            hi + 0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[10], D_800F5954_ovl24[11],
                            lo + 0x80);
    }
    arg0[4] = 2;
}

#include "shared/func_800F428C_ovl24.c"

#define D_800D1CB4 D_800D1CB8
#define D_800F596C_ovl24 D_800F5978_ovl24

#define func_800F428C_ovl24 func_800F4430_ovl24
#include "shared/func_800F428C_ovl24.c"
#undef func_800F428C_ovl24
#undef D_800D1CB4
#undef D_800F596C_ovl24

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

void func_800F4DD0_ovl24(u8* obj, s16 x, s16 y, u8 kind, u8 arg4);
extern s32 D_800D1CAC;
extern s16 D_800F5984_ovl24[];

void func_800F4840_ovl24(u8* obj) {
    s32 n;
    s32 q;
    s32 r;
    s32 v = D_800D1CAC;

    if (v <= 0) {
        n = 0;
    } else {
        n = v / 216000;
        if (v != n * 216000) {
            n += 1;
        }
    }
    if (n == 0) {
        func_800F4DD0_ovl24(obj, D_800F5984_ovl24[2], D_800F5984_ovl24[3], 0x80,
                            1);
    } else {
        q = n / 10;
        r = n % 10;
        if (q != 0) {
            func_800F4DD0_ovl24(obj, D_800F5984_ovl24[0], D_800F5984_ovl24[1],
                                q + 0x80, 1);
        }
        func_800F4DD0_ovl24(obj, D_800F5984_ovl24[2], D_800F5984_ovl24[3],
                            r + 0x80, 1);
    }
    obj[5] = 0;
}
