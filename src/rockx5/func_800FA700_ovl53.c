#include "types.h"

extern u8 D_800FAF9C_ovl53[];
extern u8 D_800FAD9C_ovl53[];
extern u8 D_800FB39C_ovl53[];
extern u8 D_800FB19C_ovl53[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
void func_8002385C(s32, s32, s32);

void func_800FA700_ovl53(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FAF9C_ovl53, D_800FAD9C_ovl53, 0x100, arg0->unk4, 0x1E);
    func_8002C338(0x60, D_800FAF9C_ovl53, 0x10);
    func_8002C3CC(D_800FB39C_ovl53, D_800FB19C_ovl53, 0x100, 0x1E - arg0->unk4,
                  0x1E);
    func_8002C338(0x70, D_800FB39C_ovl53, 0x10);
    if (arg0->unk4 >= 0x1E) {
        func_8002385C(0x51, 0xFF, 0);
        arg0->unk1++;
    }
}
