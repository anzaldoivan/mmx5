#include "types.h"

extern u8 D_800FBE20_ovl58[];
extern u8 D_800FBE00_ovl58[];
extern u8 D_800FC040_ovl58[];
extern u8 D_800FBE40_ovl58[];

void func_8002C1C8(void);
void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
void func_8002385C(s32, s32, s32);

void func_800FB394_ovl58(Ovl45State* arg0) {
    func_8002C1C8();
    arg0->unk4++;
    func_8002C3CC(D_800FBE20_ovl58, D_800FBE00_ovl58, 0x10, arg0->unk4, 0x3C);
    func_8002C338(0x40, D_800FBE20_ovl58, 1);
    func_8002C3CC(D_800FC040_ovl58, D_800FBE40_ovl58, 0x100, 0x3C - arg0->unk4,
                  0x3C);
    func_8002C338(0xD0, D_800FC040_ovl58, 0x10);
    if (arg0->unk4 >= 0x3C) {
        arg0->unk4 = 0;
        func_8002385C(0x78, 0xFF, 0);
        arg0->unk1++;
    }
}
