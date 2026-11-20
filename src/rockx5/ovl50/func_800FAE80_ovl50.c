#include "types.h"
#include "mmx5/ovl50.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;
extern u8 D_800FB3E0_ovl50[];
extern u8 D_8009A298;

void func_800FAE80_ovl50(Actor50* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(1, D_800FB3C8_ovl50[2], D_800FB3C8_ovl50[3],
                      D_800FB3E0_ovl50);
        D_8009A298 = 1;
        func_8002385C(0x3D, 0xFF, 0);
        arg0->step++;
    }
}
