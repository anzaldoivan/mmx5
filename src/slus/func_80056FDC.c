#include "types.h"

extern u8* func_8002D144(void);
extern u8 D_800D1C00[];

void func_80056FDC(u8* a0) {
    u8* g = D_800D1C00;
    u8 c = g[0xC];
    u8* r;

    if ((u32)(c - 1) < 8 && ((g[0x4C] >> ((s8)c - 1)) & 1)) {
        g[0xF] = 1;
        return;
    }
    r = func_8002D144();
    if (r != 0) {
        r[0] = 1;
        r[1] = 4;
        *(u8**)(a0 + 0x14) = r;
    }
    *(s16*)(a0 + 0x18) = 0;
    a0[0x1A] = 5;
    a0[0x1B] = 0;
    a0[4]++;
}
