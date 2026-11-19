#include "types.h"

void func_800EF068_ovl16(Ovl16Obj* obj) {
    if (obj->unk2 == 1) {
        obj->unk28 -= obj->unk44;
        obj->unk30 -= obj->unk44;
    } else {
        obj->unk18 += obj->unk44;
        obj->unk20 += obj->unk44;
    }
    if (--obj->unk38 == 0) {
        obj->unk4++;
    }
}
