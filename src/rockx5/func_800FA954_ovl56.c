#include "types.h"

extern u8 D_800FC900_ovl56[];
extern u8 D_800FC700_ovl56[];
extern u8 D_800FCD00_ovl56[];
extern u8 D_800FCB00_ovl56[];
extern u8 D_800FD100_ovl56[];
extern u8 D_800FCF00_ovl56[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);

void func_800FA954_ovl56(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FC900_ovl56, D_800FC700_ovl56, 0x100, arg0->unk4, 0x5A);
    func_8002C338(0x120, D_800FC900_ovl56, 0x10);
    func_8002C3CC(D_800FCD00_ovl56, D_800FCB00_ovl56, 0x100, 0x5A - arg0->unk4,
                  0x5A);
    func_8002C338(0x130, D_800FCD00_ovl56, 0x10);
    func_8002C3CC(D_800FD100_ovl56, D_800FCF00_ovl56, 0x100, 0x5A - arg0->unk4,
                  0x5A);
    func_8002C338(0x140, D_800FD100_ovl56, 0x10);
    if (arg0->unk4 >= 0x5A) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
