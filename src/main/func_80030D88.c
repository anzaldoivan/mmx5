#include "types.h"

extern s16 D_800E930A;
extern s16 D_800E930C;
extern s16 D_800E930E;
extern s16 D_800E9310;
extern s16 D_800E9312;
extern s16 D_800E9314;
extern s16 D_800E9316;
extern s16 D_800E9318;

void func_80030D88(u8* a0) {
    u8* p = *(u8**)(a0 + 0x68);
    u16 y;
    u8 c;
    u16 z;

    D_800E930E = (s8)p[0];
    y = *(u16*)(a0 + 0xA);
    D_800E9310 = (s8)p[1];
    D_800E930A = p[2];
    c = p[3];
    z = *(u16*)(a0 + 0xE);
    D_800E9312 = y;
    D_800E9314 = z;
    D_800E930C = c;
    if (a0[0x15] == 0) {
        D_800E9316 = y + D_800E930E;
    } else {
        D_800E9316 = y - D_800E930E;
    }
    D_800E9318 = D_800E9314 + D_800E9310;
}
