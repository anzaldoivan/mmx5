#include "types.h"

extern s32 func_8001D3A8(u8);
extern s32 func_8001D7E8(u8);
extern s32 func_8001D8B4(u8);
extern s32 func_8002C50C(void);
extern u8 D_8009A427;
extern u8 D_800E81D8[];
extern u8 D_800E8332;

static inline s32 func_800F1248_ovl24_poll(u8* arg0) {
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

void func_800F1248_ovl24(u8* arg0) {
    u8* p;
    u8* q;
    u8* b;
    s32 r;

    p = D_800E81D8;
    if (p[0xA] != 0) {
        p[0xA]--;
        return;
    }
    if (func_800F1248_ovl24_poll(arg0) != 0) {
        return;
    }
    q = D_800E81D8;
    r = func_8001D3A8(q[6]) & 0xFF;
    if (r != 0 && r != 2) {
        func_8002C50C();
        D_8009A427 = 0;
        arg0[1] = 0xA;
        arg0[2] = 0;
        if (r == 1) {
            q[8] = 0;
            arg0[3] = 1;
            return;
        }
        q[8] = 4;
        arg0[3] = 1;
        return;
    }
    b = D_800E81D8;
    if (func_8001D8B4(b[6]) == 0) {
        arg0[2]++;
        (*(u8**)(b + 0xC))[0] = 0xFF;
        (*(u8**)(b + 0xC))[0x158] = 0xFF;
        (*(u8**)(b + 0xC))[0x2B0] = 0xFF;
        (*(u8**)(b + 0xC))[0x408] = 0xFF;
        (*(u8**)(b + 0xC))[0x560] = 0xFF;
        (*(u8**)(b + 0xC))[0x6B8] = 0xFF;
        (*(u8**)(b + 0xC))[0x810] = 0xFF;
        (*(u8**)(b + 0xC))[0x968] = 0xFF;
        D_800E8332 = 0;
        arg0[3] = 0xF;
    } else {
        func_8002C50C();
        b[8] = 4;
        arg0[1] = 0xA;
        arg0[2] = 0;
        arg0[3] = 0x10;
    }
}
