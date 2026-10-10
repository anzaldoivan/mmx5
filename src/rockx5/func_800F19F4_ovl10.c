#include "types.h"

extern s16 D_8009A0AA;
extern void func_800171E8(Obj3DD4*, s32);

void func_800F19F4_ovl10(Obj3DD4* e) {
    func_800171E8(e, 3);
    if (D_8009A0AA <= e->unkA) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    e->unk6++;
}
