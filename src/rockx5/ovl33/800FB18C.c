#include "types.h"
#include "mmx5/ovl33.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl06.h"
#include "mmx5/object.h"
#include "addr.h"

extern s32 D_800FEADC_ovl33[];
extern s32 D_800FEAE0_ovl33[];
extern s16 D_800FEDFC_ovl33[];
extern s16 D_800FEDFE_ovl33[];

void func_800FB18C_ovl33(Obj8AA8* o) {
    s32 d;

    set_animation(o, 0x13);
    o->unk50 = D_800FEADC_ovl33;
    o->unk54 = D_800FEAE0_ovl33;
    if (D_8009A0AA > D_800FF054_ovl33 + 0x1260) {
        o->unk15 = 0x40;
        o->unk20 = -0x60000;
        d = D_800FEDFC_ovl33[0] + D_800FF054_ovl33 - o->unkA;
        if (d < 0) {
            d = o->unkA - (D_800FEDFC_ovl33[0] + D_800FF054_ovl33);
        }
    } else {
        o->unk15 = 0;
        o->unk20 = 0x60000;
        d = D_800FEDFE_ovl33[0] + D_800FF054_ovl33 - o->unkA;
        if (d < 0) {
            d = o->unkA - (D_800FEDFE_ovl33[0] + D_800FF054_ovl33);
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

#define D_800FF500_ovl06 D_800FEE00_ovl33
#define D_800FF510_ovl06 D_800FEE10_ovl33
#define D_800FF520_ovl06 D_800FEE20_ovl33
#define D_800FF530_ovl06 D_800FEE30_ovl33
#define D_800FF94C_ovl06 D_800FF054_ovl33
#define D_800FF94E_ovl06 D_800FF056_ovl33
#define func_800FAF38_ovl06 func_800FD4FC_ovl33
#define func_800F8CE8_ovl06 func_800FB2AC_ovl33
#define D_800FF508_ovl06 D_800FEE08_ovl33
#define D_800FF518_ovl06 D_800FEE18_ovl33
#define D_800FF528_ovl06 D_800FEE28_ovl33
#define D_800FF538_ovl06 D_800FEE38_ovl33
#define func_800F8ED4_ovl06 func_800FB498_ovl33
#include "shared/func_800F8CE8_ovl06.c"
#undef func_800F8CE8_ovl06
#undef D_800FF500_ovl06
#undef D_800FF510_ovl06
#undef D_800FF520_ovl06
#undef D_800FF530_ovl06
#undef func_800FAF38_ovl06
#undef func_800F8ED4_ovl06
