#include "types.h"

void func_800EEFEC_ovl16(Ovl16Obj* obj) {
    if (obj->unk2 != 0) {
        obj->unk14 += obj->unk40;
        obj->unk2C += obj->unk40;
    } else {
        obj->unk1C -= obj->unk40;
        obj->unk24 -= obj->unk40;
    }
    if (--obj->unk38 == 0) {
        obj->unk4++;
    }
}
