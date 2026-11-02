#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern s32 func_8001D7E8(u8);
extern u8* func_8002D27C(void);
extern void func_800F19F0_ovl24(void);
extern u8 D_8009A427;
extern u16 D_800C931C[];
extern X4_EngineObj D_800D1C00;
extern u8 D_800E81D8[];
extern u8* D_800F5F84_ovl24;

static inline s32 func_800F1688_ovl24_poll(u8* arg0) {
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

void func_800F1688_ovl24(u8* arg0) {
    u8* p;
    u8* b;
    s32 n;

    if (D_800E81D8[0xA] != 0) {
        D_800E81D8[0xA]--;
        return;
    }
    if (func_800F1688_ovl24_poll(arg0) != 0) {
        return;
    }
    if (D_800C931C[2] & 0xA000) {
        func_80016490(0, 0xC, 0);
        D_800D1C00.unkA ^= 1;
    }
    if (D_800C931C[2] & 0x40) {
        func_80016490(0, 0x22, 0);
        p = D_800F5F84_ovl24;
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (D_800D1C00.unkA == 0) {
            b = D_800E81D8;
            if (**(u8**)(b + 0xC) != 0xFF) {
                p = func_8002D27C();
                if (p != 0) {
                    p[0] = 1;
                    p[1] = 0x3E;
                    p[2] = 0x11;
                }
                D_800F5F84_ovl24 = p;
                b[0xA] = 3;
                *(s16*)(arg0 + 0xA) = 1;
                arg0[1]++;
                func_800F19F0_ovl24();
                arg0[3] = 0xA;
                return;
            }
            b[0xA] = 3;
            arg0[3] = 0xB;
            arg0[1] += 2;
            return;
        }
        arg0[3] = 8;
        arg0[1]--;
        func_800F19F0_ovl24();
    }
}
