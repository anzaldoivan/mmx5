#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern s32 D_800E92F8;

void func_800FB484_ovl55(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x4C, 0xFF, 0);
        D_800E92F8 = 1;
        arg0->unk1++;
    }
}
