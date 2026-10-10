#include "types.h"

/* e: Ovl45State (include/types.h), same shape as this function's accesses */
extern u8 D_80091C44;
extern u8 D_800FB9E0_ovl55[];
extern u8 D_8009A298;

void func_80028B18(s32, s32, s32, void*);
void func_8002385C(s32, s32, s32);

void func_800FAB08_ovl55(Ovl45State* e) {
    if (D_80091C44 == 0) {
        func_80028B18(1, 0x10, 0x10, D_800FB9E0_ovl55);
        D_8009A298 = 1;
        e->unk4 = 0;
        func_8002385C(0x5A, 0xFF, 0);
        e->unk1++;
    }
}
