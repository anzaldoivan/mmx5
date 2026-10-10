#include "types.h"

extern u8 D_800FC100_ovl56[];
extern u8 D_800FBF00_ovl56[];
extern u8 D_800FC500_ovl56[];
extern u8 D_800FC300_ovl56[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
void func_8002385C(s32, s32, s32);

void func_800FAD14_ovl56(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FC100_ovl56, D_800FBF00_ovl56, 0x100, arg0->unk4, 0x3C);
    func_8002C338(0x40, D_800FC100_ovl56, 0x10);
    func_8002C3CC(D_800FC500_ovl56, D_800FC300_ovl56, 0x100, 0x3C - arg0->unk4,
                  0x3C);
    func_8002C338(0x50, D_800FC500_ovl56, 0x10);
    if (arg0->unk4 >= 0x3C) {
        arg0->unk1++;
        func_8002385C(0x5F, 0xFF, 0);
    }
}
