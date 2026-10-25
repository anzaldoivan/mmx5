#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_8009A1F8[];

void func_800FA74C_ovl46(u8* e) {
    u8* p = D_8009A1F8;
    s32 a = *(s32*)(p + 0x60) + 0xCCCCC;
    s32 b = *(s32*)(p + 0xB4) + 0xCCCCC;

    p[0xA0] = 1;
    p[0xF4] = 1;
    *(s32*)(p + 0x60) = a;
    *(s32*)(p + 0xB4) = b;
    if (a > 0xFFFFFF) {
        func_8002385C(0x1D, 0xFF, 0);
        *(s32*)(p + 0x60) = 0x1000000;
        *(s32*)(p + 0xB4) = 0x2000000;
        e[1]++;
    }
}
