#include "types.h"
#include "addr.h"

extern void func_8003D29C(s32, s32);
extern u8* func_8002D144(void);
extern s8 D_800D1C0F;
extern signed char D_8009A0A5;
extern u8 D_8009A1F8[];

void func_800F3EC8_ovl26(u8* a0) {
    u8* g;
    u8* p;

    if (D_800D1C0F == 0 && D_8009A0A5 == 0x14) {
        g = D_8009A1F8;
        *(s32*)(a0 + 0x90) = (s8)g[0x48];
        g[0x48] = 1;
        g[0x47] = 2;
        func_8003D29C(0x1D, 0x40);
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x84) = p;
        }
        *(s16*)(a0 + 0x7C) = 0xA0;
        a0[6]++;
    }
}
