#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C1D;
extern u16 D_80100E94_ovl07[][2];

void func_800F1A2C_ovl07(u8* arg0) {
    u8* p;
    u16 tmp;

    if (D_800D1C1D > 0) {
        func_8002D720(arg0);
    } else {
        p = D_8009A1F8.u;
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

extern s16 D_8009A202;
extern u16 D_80100E94_ovl07[][2];

void func_800F1AD8_ovl07(u8* arg0) {
    if (D_8009A202 >= (s16)D_80100E94_ovl07[((s8*)arg0)[2]][0]) {
        arg0[4]++;
    }
}

extern u16 D_80100E94_ovl07[][2];

void func_800F1B24_ovl07(u8* arg0) {
    u8* p;

    p = D_8009A1F8.u;
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
