#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s32 D_800FEADC_ovl33[];
extern s32 D_800FEAE0_ovl33[];
extern s16 D_800FF054_ovl33;
extern s16 D_800FF056_ovl33;
extern s16 D_8009A0AA;
extern s16 D_800FEDF4_ovl33[][2];

void func_800FA980_ovl33(u8* obj) {
    s32 i;
    s32 dx;
    s32 a;
    s32 t;
    s32 u;
    s32 w;

    func_800171E8(obj, 0x13);
    *(s32**)(obj + 0x50) = D_800FEADC_ovl33;
    ((s32**)obj)[0x54 / 4] = D_800FEAE0_ovl33;
    i = 0;
    if (D_8009A0AA > D_800FF054_ovl33 + 0x1260) {
        obj[0x15] = 0x40;
        dx = D_800FEDF4_ovl33[i][0] + D_800FF054_ovl33 - *(s16*)(obj + 0xA);
    } else {
        i = 1;
        obj[0x15] = 0;
        dx = D_800FEDF4_ovl33[i][0] + D_800FF054_ovl33 - *(s16*)(obj + 0xA);
    }
    a = ratan2(*(s16*)(obj + 0xE) - (D_800FEDF4_ovl33[i][1] + D_800FF056_ovl33),
               dx);
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    t = rcos(a);
    u = t << 4;
    *(s32*)(obj + 0x20) = ((t << 5) + u) << 1;
    t = rsin(a);
    w = t << 4;
    t = (t << 5) + w;
    *(s32*)(obj + 0x24) = t << 1;
    obj[6]++;
}
