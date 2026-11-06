#include "types.h"

extern s32 func_8002C50C(void);
extern void func_80013438(u8*, u8*);
extern void func_8002002C(s32);
extern s16 func_8001FF18(void*, s32);
extern u8* func_8002D53C(void);
extern u8* func_8002D27C(void);
extern u8* D_800BE9A8;
extern u8 D_800E81D8[];
extern u8 D_8009A427;
extern u8 D_80070F74[];

void func_8001DBEC(u8* a0) {
    u8* p;
    u8* v;

    func_8002C50C();
    v = D_800BE9A8;
    *(u8**)D_800E81D8 = v;
    *(u8**)(D_800E81D8 + 0xC) = v + 0x200;
    func_80013438(v, v + 0x1FFC);
    D_8009A427 = 0;
    func_8002002C(0);
    D_800E81D8[9] = 0;
    D_800E81D8[6] = 0;
    func_8001FF18(D_80070F74, 0);
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xE;
        p[2] = 0;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0x3E;
        p[2] = 0;
    }
    a0[3] = 0;
    D_800E81D8[0xA] = 3;
    a0[1]++;
}
