#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "addr.h"

extern s16 D_800FF4FC_ovl06[];
extern s16 D_800FF4FE_ovl06[];

void func_800F8BC8_ovl06(Obj8AA8* o) {
    s32 d;

    set_animation(o, 0x13);
    o->unk50 = D_800FF1DC_ovl06.w;
    o->unk54 = D_800FF1E0_ovl06.w;
    if (D_8009A0AA > D_800FF94C_ovl06 + 0x1260) {
        o->unk15 = 0x40;
        o->unk20 = -0x60000;
        d = D_800FF4FC_ovl06[0] + D_800FF94C_ovl06 - o->unkA;
        if (d < 0) {
            d = o->unkA - (D_800FF4FC_ovl06[0] + D_800FF94C_ovl06);
        }
    } else {
        o->unk15 = 0;
        o->unk20 = 0x60000;
        d = D_800FF4FE_ovl06[0] + D_800FF94C_ovl06 - o->unkA;
        if (d < 0) {
            d = o->unkA - (D_800FF4FE_ovl06[0] + D_800FF94C_ovl06);
        }
    }
    if (d < 7) {
        d = 1;
    } else {
        d = d / 6;
    }
    o->unk28 = 0;
    o->unk2C = 0xC0000 / d;
    o->unk24 = 0x60000;
    o->unk6++;
}

#include "shared/func_800F8CE8_ovl06.c"
