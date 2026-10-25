#include "types.h"

extern u8* func_8002D53C(void);
extern u8* D_800E95A8[22];

void func_80057080(u8* a0) {
    u8* p;

    if (*(u16*)(a0 + 0x18) == 0) {
        p = func_8002D53C();
        if (p != 0) {
            *(s8*)p = -0x7D;
            p[1] = 3;
            p[2] = a0[0x1B];
            D_800E95A8[a0[0x1B]] = p;
            *(u16*)(a0 + 0x18) = 2;
            a0[0x1B]++;
            if (a0[0x1B] == 22) {
                a0[0x1B] = 0;
                *(u16*)(a0 + 0x18) = 180;
                a0[5]++;
            }
        }
    } else {
        *(u16*)(a0 + 0x18) -= 1;
    }
}
