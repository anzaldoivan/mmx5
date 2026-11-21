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

void func_800EF0E4_ovl16(Ovl16Obj* obj) {
    if (obj->unk2 == 2) {
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

void func_800EF160_ovl16(Ovl16Obj* obj) {
    if (obj->unk2 == 3) {
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

#define D_800EEC60_ovl00 func_800EF1DC_ovl16
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800EF1E4_ovl16
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800EF1EC_ovl16
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
