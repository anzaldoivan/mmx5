#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_8003D9A8(u8*);
extern u8 D_800D1C00[];

void func_8003D914(u8* p) {
    u8* g;

    if (--((s8*)p)[0xD7] == 0) {
        g = D_800D1C00;
        g[0x12] = 0;
        g[0x13] = 0;
        g[0x14] = 0;
        g[0x15] = 0;
        g[0x16] = 0;
        g[0x17] = 0;
        g[0x18] = 0;
        g[0x19] = 0;
        g[0x1A] = 0;
        p[3] = 0;
        func_80016490(3, 0xC, p);
        p[0xD7] = 0;
        p[0xD6] = 0;
        p[5]++;
        func_8003D9A8(p);
    }
}
