#include "types.h"

extern void func_800171E8(Obj0470*, s32);
extern u8 D_800F1F94_ovl12[][6];

void func_800F00FC_ovl12(Obj0470* obj) {
    if (++obj->unk7C == 100) {
        func_800171E8(obj, 9);
    }
    if (obj->unk46 == 0) {
        func_800171E8(obj, 1);
        obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87++];
        obj->unk6 = 0;
    }
}
