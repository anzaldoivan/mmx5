#include "types.h"

/* e: Ovl45State (include/types.h), same shape as this function's accesses */
extern void func_80028B18(s32, s32, s32, void*);
extern void func_8002385C(s32, s32, s32);
extern u8 D_800FABD0_ovl46[];
extern u8 D_8009A298;

void func_800FA654_ovl46(Ovl45State* e) {
    if (++e->unk4 == 4) {
        func_80028B18(1, 0xD0, 0x60, D_800FABD0_ovl46);
        D_8009A298 = 1;
        func_8002385C(0x1C, 0xFF, 0);
        e->unk4 = 0;
        e->unk1++;
    }
}
