#include "types.h"

/* e: Ovl45State (include/types.h), same shape as this function's accesses */
extern void func_80028B18(s32, s32, s32, void*);
extern void func_8002C218(void);
extern void func_8002385C(s32, s32, s32);
extern u8 D_800FBA08_ovl55[];
extern u8 D_8009A298;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD0[];

void func_800FB7B8_ovl55(Ovl45State* e) {
    if (++e->unk4 >= 8) {
        func_80028B18(1, 0x340, 0x240, D_800FBA08_ovl55);
        D_8009A298 = 1;
        e->unk4 = 0;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C218();
        D_80093DD0[6] = 0xFFFF0000;
        D_80093DD0[9] = 0xFFFF;
        func_8002385C(0x4D, 0xFF, 0);
        e->unk1++;
    }
}
