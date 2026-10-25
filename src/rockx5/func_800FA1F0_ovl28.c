#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8* func_8002D1A4();
extern u8 D_800D1C00[];

void func_800FA1F0_ovl28(u8* a0) {
    u8* g;
    u8* p;

    func_80017248(a0);
    func_8002D9EC(a0, 0x30, 0x30);
    g = D_800D1C00;
    if (((s8*)g)[0x2A] == 1) {
        g[0x2A] = 2;
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 7;
            *(u8**)(p + 0x7C) = a0;
        }
    }
    p = D_800D1C00;
    if (((s8*)p)[0x2A] == 2) {
        p[0x2A] = 0;
        a0[5] = 3;
    }
}
