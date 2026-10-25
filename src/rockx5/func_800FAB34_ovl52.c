#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FAB34_ovl52(u8* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[0x4C] = 1;
        *(s32*)(D_8009A1F8 + 8) += -0xB3333;
        if (*(s32*)(D_8009A1F8 + 8) <= 0x1200000) {
            *(s32*)(D_8009A1F8 + 8) = 0x1200000;
            func_8002385C(0x4C, 0xFF, 0);
            arg0[1]++;
        }
    }
}
