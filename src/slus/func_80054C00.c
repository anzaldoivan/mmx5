#include "types.h"

extern s32 func_8003240C(u8* a0);
extern void func_80054F90(u8* a0);
extern s32 func_800549E8(u8* a0);
extern void func_8002CF70(void);
extern u8 D_8009A1F8[];
extern s8 D_800D1C1C;
extern s8 D_800D1C1D;
extern s8 D_800D1C26;

void func_80054C00(u8* a0, s32 a1, u8* a2) {
    s8 t;
    u8* p;

    func_8003240C(a0);
    func_80054F90(a0);
    t = ((s8*)a0)[2];
    if (t == 2 && !(D_800D1C26 & 8)) {
        return;
    }
    if (t == 4 && !(D_800D1C26 & 8)) {
        return;
    }
    if (func_800549E8(a0) == 0) {
        return;
    }
    if (*(s32*)(a0 + 0x7C) == 0) {
        func_8002CF70();
        D_800D1C1C = 1;
    }
    if (((s8*)a0)[2] == 1) {
        D_800D1C26 = 1;
    }
    a2[0xD4] = 1;
    if (((s8*)a0)[2] == 7) {
        D_800D1C26 = 1;
    }
    if (((s8*)a0)[2] == 6) {
        u8* q = D_8009A1F8;
        D_800D1C1D = 2;
        *(s16*)(q + 0x2A) = 0x4B0;
    }
    p = D_8009A1F8;
    *(u16*)(p + 0x34) &= 0xF;
    a0[5] = 1;
}
