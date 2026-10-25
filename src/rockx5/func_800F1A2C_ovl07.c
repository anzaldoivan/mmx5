#include "types.h"

extern void func_8002D720(u8* arg0);
extern s8 D_800D1C1D;
extern u8 D_8009A1F8[];
extern u16 D_80100E94_ovl07[][2];

void func_800F1A2C_ovl07(u8* arg0) {
    u8* p;
    u16 tmp;

    if (D_800D1C1D > 0) {
        func_8002D720(arg0);
    } else {
        p = D_8009A1F8;
        *(u16*)(arg0 + 0x18) = *(u16*)(p + 0x2A);
        *(u16*)(arg0 + 0x1A) = *(u16*)(p + 0x28);
        *(u16*)(p + 0x26) = D_80100E94_ovl07[((s8*)arg0)[2]][0];
        tmp = D_80100E94_ovl07[((s8*)arg0)[2]][0];
        p[0x47] = 6;
        *(u16*)(p + 0x30) = 0;
        *(u16*)(p + 0x32) = 0x140;
        p[0x51] = 0;
        *(u16*)(p + 0x24) = tmp;
        arg0[4]++;
    }
}
