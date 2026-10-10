#include "types.h"

extern u8 D_80091C44;
extern s16 D_800FB8C8_ovl49[];
extern u8 D_800FB8E0_ovl49[];
extern u8 D_8009A244;

void func_80028B18(s32, s32, s32, void*);
void func_8002385C(s32, s32, s32);

void func_800FB15C_ovl49(Actor50* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(0, D_800FB8C8_ovl49[0], D_800FB8C8_ovl49[1],
                      D_800FB8E0_ovl49);
        D_8009A244 = 1;
        func_8002385C(0x30, 0xFF, 0);
        arg0->step++;
    }
}
