#include "types.h"

extern u8 D_800D1C00[];

void func_800F3048_ovl20(u8* arg0) {
    u8* p = D_800D1C00;
    s32 t = ((s8*)p)[0x27];
    s32 c;
    s32 m;

    if (t < 0x20) {
        c = t;
        m = 0x1F;
        if (((s8*)p)[0x28] != ((s8*)arg0)[2]) {
            m = 0xA;
        }
        c = (u32)((m << 8) * c) / 31 >> 8;
        if ((u32)c >= 0x20) {
            c = 0x1F;
        }
        c = c | (c << 5) | (c << 10);
        *(u16*)(arg0 + 0x34) = c;
    } else {
        arg0[3] = 0;
        arg0[4]++;
    }
}
