#include "types.h"

extern void func_80013438(s32, s32);
extern void func_8001FF18(void*, s32);
extern void func_8002002C(s32);
extern s32 func_8002C50C(void);
extern u8* func_8002D27C(void);
extern u8* func_8002D53C(void);
extern u8 D_80070F74[];
extern u8 D_8009A427;
extern s32 D_800BE9A8;
extern u8 D_800E81D8[];

void func_800F2EDC_ovl24(u8* arg0) {
    u8* base;
    u8* p;
    s32 v;

    func_8002C50C();
    v = D_800BE9A8;
    *(s32*)D_800E81D8 = v;
    base = D_800E81D8;
    ((s32*)base)[3] = v + 0x200;
    func_80013438(v, v + 0x1FFC);
    D_8009A427 = 0;
    func_8002002C(0);
    base[9] = 1;
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
    arg0[3] = 0;
    base[6] = 0;
    base[10] = 3;
    arg0[1]++;
}
