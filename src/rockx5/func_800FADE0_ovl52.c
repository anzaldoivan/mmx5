#include "types.h"

/* e: Ovl45State (include/types.h), same shape as this function's accesses */
extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_800FB0D8_ovl52[];
extern u8 D_8009A298;

void func_800FADE0_ovl52(Ovl45State* e) {
    if (++e->unk4 >= 8) {
        func_80028B18(1, 0x340, 0x240, D_800FB0D8_ovl52);
        D_8009A298 = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}
