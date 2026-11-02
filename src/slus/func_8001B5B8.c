#include "types.h"

extern s32 func_8001D7E8(u8);
extern void func_8001B984(void);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_8002C50C(void);
extern u8* func_8002D27C(void);
extern u8 D_8009A420[];
extern u8 D_8009A427;
extern Pad800218E0 D_800C931C;
extern u8 D_800D1F28[];
extern void* D_800E81D4;
extern u8 D_800E81D8[];

static inline s32 func_8001B5B8_start(u8* arg0) {
    u8* b = D_800E81D8;
    s32 t;

    t = func_8001D7E8(b[6]);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;

        if (t == one) {
            arg0[1] = 5;
            b[8] = one;
        } else {
            arg0[1] = 5;
            b[8] = two;
        }
        arg0[3] = one;
        do {
            D_8009A427 = 0;
        } while (0); // !FAKE: keeps the flag set after the store (block order)
        return 1;
    }
    return 0;
}

void func_8001B5B8(u8* arg0) {
    s32 i;
    u8* p;
    u8* b;
    u8* q;
    u8* e;
    u8* f;
    u8* r;

    if (func_8001B5B8_start(arg0) != 0) {
        return;
    }
    if (D_800C931C.unk4 & 0x1000) {
        if (D_8009A420[7] == 0) {
            for (i = 0; i < 7; i++) {
                p = D_800E81D8;
                *(u8**)(p + 0xC) += 0x158;
            }
            D_8009A420[7] = 7;
        } else {
            e = D_800E81D8;
            q = *(u8**)(e + 0xC);
            D_8009A420[7]--;
            *(u8**)(e + 0xC) = q - 0x158;
        }
        func_8001B984();
    }
    if (D_800C931C.unk4 & 0x4000) {
        if (D_8009A420[7] == 7) {
            for (i = 0; i < 7; i++) {
                p = D_800E81D8;
                *(u8**)(p + 0xC) -= 0x158;
            }
            D_8009A420[7] = 0;
        } else {
            f = D_800E81D8;
            r = *(u8**)(f + 0xC);
            D_8009A420[7]++;
            *(u8**)(f + 0xC) = r + 0x158;
        }
        func_8001B984();
    }
    if (D_800C931C.unk4 & 0x10) {
        func_80016490(0, 0x22, 0);
        func_8002C50C();
        D_800D1F28[0] = 7;
        D_800D1F28[1] = 5;
        return;
    }
    b = D_800E81D8;
    if ((D_800C931C.unk4 & 0x40) && **(u8**)(b + 0xC) != 0xFF) {
        func_80016490(0, 0x22, 0);
        b[7] = D_8009A427;
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x3E;
            p[2] = 0x11;
        }
        D_800E81D4 = p;
        b[0xA] = 3;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[3] = 4;
        arg0[1]++;
        func_8001B984();
    }
}
