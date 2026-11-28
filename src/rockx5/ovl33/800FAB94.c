#include "types.h"
#include "mmx5/ovl33.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl06.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FEDF4_ovl33[][2];

void func_800FAB94_ovl33(u8* obj) {
    s32 i;
    s32 ang;
    s32 c;
    s32 t;
    s32 sn;
    s32 t2;

    set_animation(obj, 0x13);
    *(s32**)(obj + 0x50) = D_800FEADC_ovl33.w;
    ((s32**)obj)[0x54 / 4] = D_800FEAE0_ovl33.w;
    if (D_8009A0AA > D_800FF054_ovl33 + 0x1260) {
        i = 0;
        obj[0x15] = 0x40;
    } else {
        i = 1;
        obj[0x15] = 0;
    }
    ang = ratan2(
        *(s16*)(obj + 0xE) - (D_800FEDF4_ovl33[i][1] + D_800FF056_ovl33),
        (D_800FEDF4_ovl33[i][0] + D_800FF054_ovl33) - *(s16*)(obj + 0xA));
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    c = rcos(ang);
    t = c << 4;
    *(s32*)(obj + 0x20) = ((c << 5) + t) << 1;
    sn = rsin(ang);
    t2 = sn << 4;
    *(s32*)(obj + 0x24) = ((sn << 5) + t2) << 1;
    obj[6]++;
}

#define D_800FF1E4_ovl06 D_800FEAE4_ovl33
#define D_800FF1E8_ovl06 D_800FEAE8_ovl33
#define D_800FF4F4_ovl06 D_800FEDF4_ovl33
#define D_800FF94C_ovl06 D_800FF054_ovl33
#define D_800FF94E_ovl06 D_800FF056_ovl33
#define func_800F86E8_ovl06 func_800FACAC_ovl33
#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33
#define D_800FF1DC_ovl06 D_800FEADC_ovl33
#define D_800FF1E0_ovl06 D_800FEAE0_ovl33
#define func_800F8864_ovl06 func_800FAE28_ovl33
#include "shared/func_800F86E8_ovl06.c"
#undef func_800F86E8_ovl06
#undef D_800FF1E4_ovl06
#undef D_800FF1E8_ovl06
#undef D_800FF4F4_ovl06
#undef D_800FF94C_ovl06
#undef D_800FF94E_ovl06
#undef func_800F8864_ovl06
