#include "types.h"

extern u8 D_80091C44;
extern s16 D_800FB3C8_ovl50[];
extern u8 D_800FB3E8_ovl50[];
extern u8 D_8009A298;

void func_80028B18(s32, s32, s32, void*);
void func_8002385C(s32, s32, s32);

void func_800FAEF8_ovl50(Actor50* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(1, D_800FB3C8_ovl50[4], D_800FB3C8_ovl50[5],
                      D_800FB3E8_ovl50);
        D_8009A298 = 1;
        func_8002385C(0x3E, 0xFF, 0);
        arg0->step++;
    }
}
