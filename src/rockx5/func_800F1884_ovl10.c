#include "types.h"

extern void func_800171E8(Obj1884*, s32);
extern u8 D_80075340[];

void func_800F1884_ovl10(Obj1884* arg0) {
    func_800171E8(arg0, 1);
    arg0->unk58 = D_80075340;
    arg0->unk6++;
}
