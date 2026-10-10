#include "types.h"

extern s16 D_8009A0AA;
extern void func_800171E8(Obj3DD4*, s32);

void func_800F9E90_ovl28(Obj3DD4* e) {
    func_800171E8(e, 7);
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    e->unk7C = 0;
    e->unk7E = 0;
    e->unk6++;
}
