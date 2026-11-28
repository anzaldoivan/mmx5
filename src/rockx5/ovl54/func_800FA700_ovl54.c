#include "types.h"
#include "mmx5/ovl54.h"
#include "mmx5/globals.h"

extern u8 D_800FAF54_ovl54[];
extern u8 D_800FB354_ovl54[];

void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FA700_ovl54(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FAF54_ovl54, D_800FAD54_ovl54, 0x100, arg0->unk4, 0x1E);
    ((s32(*)())load_palette)(0x60, D_800FAF54_ovl54, 0x10);
    func_8002C3CC(D_800FB354_ovl54, D_800FB154_ovl54, 0x100, 0x1E - arg0->unk4,
                  0x1E);
    ((s32(*)())load_palette)(0x70, D_800FB354_ovl54, 0x10);
    if (arg0->unk4 >= 0x1E) {
        func_8002385C(0x56, 0xFF, 0);
        arg0->unk1++;
    }
}
