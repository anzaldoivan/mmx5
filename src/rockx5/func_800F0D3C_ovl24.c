#include "types.h"

extern s32 func_8001D7E8(u8);
extern s32 func_8001D3A8(u8);
extern s32 func_8001D6BC(s32, u8*, u8*);
extern s32 func_8001D580(s32, s32, s32);
extern void func_8001DB78(s32);
extern void func_8002C50C(void);
extern s16 func_8001FF18(void*, s32);
extern u8* func_8002D53C(void);
extern u8* func_8002D27C(void);
extern void func_800F19F0_ovl24(void);
extern u8 D_800E81D8[];
extern u8 D_800E81E8[];
extern u8 D_8009A427;
extern u8 D_8009A420[];
extern u8 D_800EE974_ovl24[];
extern u8 D_800EE978_ovl24[];
extern u8 D_80070F98[];

static inline s32 func_800F0D3C_ovl24_poll(u8* arg0) {
    s32 t;

    t = func_8001D7E8(D_800E81D8[6]);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            arg0[1] = 0xA;
            D_800E81D8[8] = one;
        } else {
            arg0[1] = 0xA;
            D_800E81D8[8] = two;
        }
        arg0[3] = one;
        do {
            D_8009A427 = 0;
        } while (0); // !FAKE: do-while(0) for the register choice
        return 1;
    }
    return 0;
}

void func_800F0D3C_ovl24(u8* arg0) {
    u8* p;
    u8* q;
    u8* s;
    u8* g;
    u8* m;
    u8* o;
    u32 r;
    s32 one;

    p = D_800E81D8;
    if (p[0xA] != 0) {
        p[0xA]--;
        return;
    }
    if (func_800F0D3C_ovl24_poll(arg0) != 0) {
        return;
    }
    q = D_800E81D8;
    r = func_8001D3A8(q[6]);
    g = D_8009A420;
    g[7] = 0;
    switch (r) {
    case 1:
        arg0[1] = 0xA;
        q[8] = r;
        arg0[3] = r;
        return;
    case 2:
        arg0[2] = 0;
        arg0[1]++;
        return;
    case 3:
        arg0[1] = 0xA;
        q[8] = 2;
        arg0[3] = 0x12;
        return;
    case 0:
        s = D_800E81E8;
        if (func_8001D6BC(q[6], s, D_800EE974_ovl24) != 0) {
            return;
        }
        if (*(s32*)(s + 0x14C) == 0x1E000) {
            if (func_8001D6BC(q[6], s, D_800EE978_ovl24) != 0) {
                return;
            }
            if (s[0x14A] != 0) {
                if (func_8001D580(*(s32*)D_800E81D8, q[6], 0x2000) != 0) {
                    return;
                }
                func_8001DB78(*(s32*)(q + 0xC));
                arg0[1] += 2;
            } else {
                arg0[1] = 0xA;
                q[8] = 3;
                g[7] = 0;
                arg0[3] = 5;
                return;
            }
        } else {
            if (func_8001D6BC(q[6], s, D_800EE978_ovl24) != 0) {
                return;
            }
            if (s[0x14A] != 0) {
                if (func_8001D580(*(s32*)D_800E81D8, q[6], 0x2000) != 0) {
                    return;
                }
                func_8001DB78(*(s32*)(q + 0xC));
                arg0[1] += 2;
            } else {
                (*(u8**)(q + 0xC))[0] = 0xFF;
                (*(u8**)(q + 0xC))[0x158] = 0xFF;
                (*(u8**)(q + 0xC))[0x2B0] = 0xFF;
                (*(u8**)(q + 0xC))[0x408] = 0xFF;
                (*(u8**)(q + 0xC))[0x560] = 0xFF;
                (*(u8**)(q + 0xC))[0x6B8] = 0xFF;
                (*(u8**)(q + 0xC))[0x810] = 0xFF;
                (*(u8**)(q + 0xC))[0x968] = 0xFF;
                arg0[1] += 2;
            }
        }
        func_8002C50C();
        func_8001FF18(D_80070F98, 0);
        one = 1;
        m = func_8002D53C();
        if (m != 0) {
            m[0] = one;
            m[1] = 0xE;
            m[2] = one;
        }
        o = func_8002D27C();
        if (o != 0) {
            o[0] = one;
            o[1] = 0x3E;
            o[2] = 0x10;
        }
        o = func_8002D27C();
        if (o != 0) {
            o[0] = one;
            o[1] = 0x3E;
            o[2] = 2;
        }
        arg0[3] = 8;
        D_8009A420[7] = 0;
        func_800F19F0_ovl24();
        return;
    }
}
