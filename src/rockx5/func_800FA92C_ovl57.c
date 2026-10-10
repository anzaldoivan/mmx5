#include "types.h"

/* e: Ovl45State (include/types.h), same shape as this function's accesses */
extern u8 D_80091C44;
extern u8 D_800FAB8C_ovl57[];
extern u8 D_8009A298;

void func_80028B18(s32, s32, s32, void*);
void func_8002385C(s32, s32, s32);

void func_800FA92C_ovl57(Ovl45State* e) {
    if (D_80091C44 == 0) {
        func_80028B18(1, 0xD0, 0x140, D_800FAB8C_ovl57);
        D_8009A298 = 1;
        func_8002385C(0x71, 0xFF, 0);
        e->unk1++;
    }
}
