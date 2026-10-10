#include "types.h"

extern u8 D_800FADE8_ovl57[];
extern u8 D_800FABE8_ovl57[];
extern u8 D_800FB1E8_ovl57[];
extern u8 D_800FAFE8_ovl57[];
extern u8 D_800FB5E8_ovl57[];
extern u8 D_800FB3E8_ovl57[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
void func_8002385C(s32, s32, s32);

void func_800FA34C_ovl57(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FADE8_ovl57, D_800FABE8_ovl57, 0x100, arg0->unk4, 0x3C);
    func_8002C338(0x40, D_800FADE8_ovl57, 0x10);
    func_8002C3CC(D_800FB1E8_ovl57, D_800FAFE8_ovl57, 0x100, 0x3C - arg0->unk4,
                  0x3C);
    func_8002C338(0x50, D_800FB1E8_ovl57, 0x10);
    func_8002C3CC(D_800FB5E8_ovl57, D_800FB3E8_ovl57, 0x100, 0x3C - arg0->unk4,
                  0x3C);
    func_8002C338(0x90, D_800FB5E8_ovl57, 0x10);
    if (arg0->unk4 >= 0x3C) {
        func_8002385C(0x6E, 0xFF, 0);
        arg0->unk1++;
    }
}
