#include "types.h"

extern u8 D_800FB800_ovl58[];
extern u8 D_800FB600_ovl58[];
extern u8 D_800FBC00_ovl58[];
extern u8 D_800FBA00_ovl58[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
void func_8002385C(s32, s32, s32);

void func_800FA680_ovl58(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FB800_ovl58, D_800FB600_ovl58, 0x100, arg0->unk4, 0x3C);
    func_8002C338(0x50, D_800FB800_ovl58, 0x10);
    func_8002C3CC(D_800FBC00_ovl58, D_800FBA00_ovl58, 0x100, 0x3C - arg0->unk4,
                  0x3C);
    func_8002C338(0x60, D_800FBC00_ovl58, 0x10);
    if (arg0->unk4 >= 0x3C) {
        arg0->unk1++;
        func_8002385C(0x5F, 0xFF, 0);
    }
}
