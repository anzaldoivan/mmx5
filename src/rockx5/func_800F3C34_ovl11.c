#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80028B18(s32, s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D27C(void);
extern u8* func_8002D0E4(void);
extern s32 func_8002DFB0(void);
extern void func_80016D54(s32, s32);
extern void func_8002A600(s32, s32, s32);

extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_8009A244;
extern u8 D_800F9BD0_ovl11[];
extern u16 D_800F9C40_ovl11[];
extern u16 D_800F9C48_ovl11[];

static inline void func_800F3C34_ovl11_se(s32 a, u8 d) {
    if (d != 0xFF) {
        func_80016490(a, d, 0);
    }
}

void func_800F3C34_ovl11(u8* o) {
    u8* g = D_8009A0A0;
    u8 t;
    u8* p;
    s32 i;

    if (((s8*)g)[0xF3] == 0) {
        o[0x85]++;
        if (!(o[0x85] & 1)) {
            u8* q = D_8009A1F8;
            (*(s16*)(q + 0x28))--;
            (*(s16*)(q + 0x2A))--;
        }
        func_8002DF54(o);
    } else if ((u8)(g[0xFA] - 2) >= 2) {
        o[0x85]++;
        if (!(o[0x85] & 1)) {
            u8* q = D_8009A1F8;
            (*(s16*)(q + 0x28))--;
            (*(s16*)(q + 0x2A))--;
        }
        func_8002DF54(o);
    }

    if (*(s16*)(o + 0xE) == 0x388 && o[0x82] == 0) {
        if (func_8002DF78() & 1) {
            t = 0;
        } else {
            t = 1;
        }
        func_800F3C34_ovl11_se(0, t);
        func_80028B18(0, 0xE10, 0x330, D_800F9BD0_ovl11);
        D_8009A244 = 1;
        o[0x82] = 1;
        for (i = 0; i < 20; i++) {
            p = func_8002D27C();
            if (p != 0) {
                u8* h;
                p[0] = 0x41;
                p[1] = 0x31;
                p[0x15] = func_8002DF78() & 0x40;
                p[2] = 1;
                *(s16*)(p + 0xA) =
                    D_800F9C40_ovl11[func_8002DF78() & 3] + 0xE10;
                *(s16*)(p + 0xE) =
                    D_800F9C48_ovl11[func_8002DF78() & 7] + 0x340;
                *(s16*)(p + 0x40) = *(s16*)(o + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
                *(s16*)(p + 0x42) = *(s16*)(o + 0x42);
                h = D_8009A0A0;
                p[0x14] = h[0x14];
            }
            p = func_8002D0E4();
            if (p != 0 && i % 5 == 0) {
                p[0] = 0x21;
                p[1] = 4;
                *(s16*)(p + 0xA) = func_8002DFB0() % 48 + 0xE10;
                *(s16*)(p + 0xE) = func_8002DFB0() % 48 + 0x330;
                p[0x16] = 1;
            }
        }
    }

    if (*(s16*)(o + 0xE) == 0x2B0) {
        o[6]++;
        {
            u8* q = D_8009A1F8;
            if (*(s16*)(q + 0x2A) == *(s16*)(q + 0x28)) {
                func_80016D54(5, 0x1D);
                func_80016490(5, 0x1B, o);
                func_8002A600(0x20, 2, 1);
            }
        }
    }
}
