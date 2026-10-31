#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s32 D_800FEADC_ovl33[];
extern s32 D_800FEAE0_ovl33[];
extern s16 D_800FEDF4_ovl33[][2];
extern s16 D_800FF054_ovl33;
extern s16 D_800FF056_ovl33;
extern s16 D_8009A0AA;

void func_800FAB94_ovl33(u8* obj) {
    s32 i;
    s32 ang;
    s32 c;
    s32 t;
    s32 sn;
    s32 t2;

    func_800171E8(obj, 0x13);
    *(s32**)(obj + 0x50) = D_800FEADC_ovl33;
    ((s32**)obj)[0x54 / 4] = D_800FEAE0_ovl33;
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
