#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80028B18(s32, s32, s32, void*);
extern u8* func_8002D53C(void);
extern u8* func_8002D27C(void);
extern u8 D_800F5FE9_ovl20;
extern u8 D_800F5FE0_ovl20[];
extern u8 D_800D1C00[];
extern s16 D_800F5108_ovl20[];
extern u8 D_8009A1F8[];
extern u8 D_800F5194_ovl20[];
extern u8 D_800F50B0_ovl20[][8];
extern u8 D_800F5058_ovl20[][8];
extern u8 D_800F512C_ovl20[][8];
extern u8 D_800F518C_ovl20[];
extern u8 D_800F5184_ovl20[];
extern u8 D_800F519C_ovl20[];

static inline s32 func_800EF2AC_ovl20_sel(u8* arg0) {
    s32 r;

    if (arg0[0x10F] == 2 || arg0[0x10F] == 4) {
        r = 8;
    } else if (arg0[0x79] >= 9) {
        r = 10;
    } else {
        r = 9;
    }
    return r;
}

void func_800EF2AC_ovl20(u8* arg0) {
    s32 n;
    s32 m;
    s32 i;
    s32 mask;
    u8* p;
    u8* q;

    if (++*(s16*)(arg0 + 8) < 4) {
        return;
    }
    n = func_8002DF78() % D_800F5FE9_ovl20;
    if (D_800F5FE0_ovl20[n] != 0) {
        i = 0;
        while (i < D_800F5FE9_ovl20 &&
               D_800F5FE0_ovl20[n = (n + 1) % D_800F5FE9_ovl20] != 0) {
            i++;
        }
    }
    D_800F5FE0_ovl20[n] = 1;
    if (n == 8) {
        m = func_800EF2AC_ovl20_sel(arg0);
    } else {
        m = n;
    }
    if (n < 8 && ((D_800D1C00[0x4C] >> D_800F5194_ovl20[n]) & 1)) {
        func_80028B18(1, D_800F5108_ovl20[n * 2], (&D_800F5108_ovl20[n * 2])[1],
                      D_800F50B0_ovl20[m]);
    } else {
        func_80028B18(1, D_800F5108_ovl20[n * 2], (&D_800F5108_ovl20[n * 2])[1],
                      D_800F5058_ovl20[m]);
    }
    D_8009A1F8[0xA0] = 1;
    *(s16*)(arg0 + 8) = 0;
    *(s16*)(arg0 + 0xA) += 1;
    D_800D1C00[0x27] = 0x20;
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 0x51;
        p[1] = 1;
        p[2] = n;
    }
    if (*(s16*)(arg0 + 0xA) < D_800F5FE9_ovl20) {
        return;
    }
    *(s16*)(arg0 + 0xA) = 0;
    *(s16*)(arg0 + 8) = 0;
    arg0[1] = 4;
    arg0[2] = 0;
    if (D_800F5FE9_ovl20 == 9) {
        func_80028B18(1, 0x2E0, 0x90,
                      D_800F512C_ovl20[func_800EF2AC_ovl20_sel(arg0)]);
        D_800D1C00[0x28] = 8;
    } else {
        func_80028B18(1, 0x2E0, 0x90, D_800F512C_ovl20);
    }
    if (D_800D1C00[0xCB] & 1) {
        func_80028B18(1, 0xA0, 0x10, D_800F518C_ovl20);
        func_80028B18(1, 0x460, 0x10, D_800F518C_ovl20);
    } else {
        func_80028B18(1, 0xA0, 0x10, D_800F5184_ovl20);
        func_80028B18(1, 0x460, 0x10, D_800F5184_ovl20);
    }
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 0x51;
        p[1] = 1;
        p[2] = 9;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xD;
        p[2] = 0;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xC;
        p[2] = 0;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xC;
        p[2] = 1;
    }
    for (i = 0; i < D_800F5FE9_ovl20; i++) {
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 0x51;
            p[1] = 1;
            p[2] = i | 0x10;
        }
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0xC;
            p[2] = i | 0x10;
        }
    }
    mask = arg0[0x4C];
    for (i = 0; i < 8; i++) {
        if (D_800F519C_ovl20[i] & mask) {
            q = func_8002D27C();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x2E;
                q[2] = i;
            }
            q = func_8002D27C();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x2E;
                q[2] = i + 0x20;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if ((arg0[0xA1] >> i) & 1) {
            q = func_8002D27C();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x27;
                q[2] = i;
            }
            q = func_8002D27C();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x27;
                q[2] = i + 8;
            }
        }
    }
}
