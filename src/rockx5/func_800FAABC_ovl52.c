#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FAABC_ovl52(u8* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[0xA0] = 1;
        *(s32*)(D_8009A1F8 + 0x5C) += -0x99999;
        if (*(s32*)(D_8009A1F8 + 0x5C) <= 0) {
            *(s32*)(D_8009A1F8 + 0x5C) = 0;
            func_8002385C(0x4B, 0xFF, 0);
            arg0[1]++;
        }
    }
}
