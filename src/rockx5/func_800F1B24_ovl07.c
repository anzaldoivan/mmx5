#include "types.h"

extern void func_8002D720(u8* arg0);
extern u8 D_8009A1F8[];
extern u16 D_80100E94_ovl07[][2];

void func_800F1B24_ovl07(u8* arg0) {
    u8* p;

    p = D_8009A1F8;
    *(u16*)(p + 0x24) = D_80100E94_ovl07[((s8*)arg0)[2]][1];
    *(u16*)(p + 0x2A) = *(u16*)(arg0 + 0x18);
    *(u16*)(p + 0x28) = *(u16*)(arg0 + 0x1A);
    p[0x51] = 1;
    *(u16*)(p + 0x30) = 0xA0;
    *(u16*)(p + 0x32) = 0xA0;
    p[0x47] = 2;
    p[0x48] = 8;
    func_8002D720(arg0);
}
