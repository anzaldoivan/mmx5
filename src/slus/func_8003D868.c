#include "types.h"

extern void func_80016D54(s32, s32);
extern void func_8001296C(s32);
extern void func_8003B33C(u8*, s32);
extern u8 D_800D1C00[];

void func_8003D868(u8* p) {
    u8* g;

    func_80016D54(1, 5);
    func_80016D54(1, 7);
    func_8001296C(0);
    if (((s8*)p)[0xD5] != 0) {
        p[3] = 0;
        p[0xD7] = 1;
    } else {
        g = D_800D1C00;
        g[0x12] = 1;
        g[0x13] = 1;
        g[0x14] = 1;
        g[0x15] = 1;
        g[0x16] = 1;
        g[0x17] = 1;
        g[0x18] = 1;
        g[0x19] = 1;
        g[0x1A] = 1;
        p[0xD7] = 8;
        func_8003B33C(p, 0x21);
    }
    p[5]++;
}
