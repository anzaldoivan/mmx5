#include "types.h"

extern u8 D_80091C44;
extern s16 D_800FB8C8_ovl49[];
extern u8 D_800FB8E8_ovl49[];
extern u8 D_8009A244;

void func_80028B18(s32, s32, s32, void*);
void func_8002385C(s32, s32, s32);

void func_800FB2C4_ovl49(Actor50* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(0, D_800FB8C8_ovl49[2], D_800FB8C8_ovl49[3],
                      D_800FB8E8_ovl49);
        D_8009A244 = 1;
        func_8002385C(0x33, 0xFF, 0);
        arg0->step++;
    }
}
