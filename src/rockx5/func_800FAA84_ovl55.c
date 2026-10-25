#include "types.h"

/* e: Ovl45State (include/types.h), same shape as this function's accesses */
extern u8 D_800FB9D8_ovl55[];
extern u8 D_8009A298;

void func_80028B18(s32, s32, s32, void*);
void func_8002385C(s32, s32, s32);

void func_800FAA84_ovl55(Ovl45State* e) {
    if (++e->unk4 >= 20) {
        func_80028B18(1, 0xD0, 0x10, D_800FB9D8_ovl55);
        D_8009A298 = 1;
        func_8002385C(0x59, 0xFF, 0);
        e->unk1++;
    }
}
