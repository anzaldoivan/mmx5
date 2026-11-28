#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FF4F4_ovl06[][2];

void func_800F85D0_ovl06(u8* obj) {
    s32 i;
    s32 ang;
    s32 c;
    s32 t;
    s32 sn;
    s32 t2;

    set_animation(obj, 0x13);
    *(s32**)(obj + 0x50) = D_800FF1DC_ovl06.w;
    ((s32**)obj)[0x54 / 4] = D_800FF1E0_ovl06.w;
    if (D_8009A0AA > D_800FF94C_ovl06 + 0x1260) {
        i = 0;
        obj[0x15] = 0x40;
    } else {
        i = 1;
        obj[0x15] = 0;
    }
    ang = ratan2(
        *(s16*)(obj + 0xE) - (D_800FF4F4_ovl06[i][1] + D_800FF94E_ovl06),
        (D_800FF4F4_ovl06[i][0] + D_800FF94C_ovl06) - *(s16*)(obj + 0xA));
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

#include "shared/func_800F86E8_ovl06.c"
