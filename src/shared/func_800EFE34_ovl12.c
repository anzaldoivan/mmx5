#include "types.h"

extern u8 D_800F1F94_ovl12[][6];

void func_800EFE34_ovl12(Ovl12Obj* obj) {
    if (obj->unk85 == 0) {
        obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87];
        obj->unk6 = 0;
        obj->unk87++;
    } else {
        obj->unk85--;
    }
}
