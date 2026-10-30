#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FF1E4_ovl06[];
extern u8 D_800FF1E8_ovl06[];
extern s16 D_800FF4F4_ovl06[][2];
extern s16 D_800FF94C_ovl06;
extern s16 D_800FF94E_ovl06;

void func_800F86E8_ovl06(u8* obj) {
    s32 i;
    s32 ang;
    s32 t;
    s32 t1;
    s32 t2;
    s32 c;
    s32 sn;
    s16 v;

    i = obj[0x15] == 0;
    ang = ratan2(
        *(s16*)(obj + 0xE) - (D_800FF4F4_ovl06[i][1] + D_800FF94E_ovl06),
        (D_800FF4F4_ovl06[i][0] + D_800FF94C_ovl06) - *(s16*)(obj + 0xA));
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    c = rcos(ang);
    t1 = c << 4;
    *(s32*)(obj + 0x20) = ((c << 5) + t1) << 1;
    sn = rsin(ang);
    t2 = sn << 4;
    *(s32*)(obj + 0x24) = ((sn << 5) + t2) << 1;
    func_80017248(obj);
    func_8002DF54(obj);
    v = *(s16*)(obj + 0xA);
    t = D_800FF4F4_ovl06[i][0] + D_800FF94C_ovl06;
    if (v >= t - 4 && t + 4 >= v) {
        v = *(s16*)(obj + 0xE);
        t = D_800FF4F4_ovl06[i][1] + D_800FF94E_ovl06;
        if (v >= t - 4 && t + 4 >= v) {
            func_800171E8(obj, 0xE);
            *(u8**)(obj + 0x50) = D_800FF1E4_ovl06;
            *(u8**)(obj + 0x54) = D_800FF1E8_ovl06;
            *(s16*)(obj + 0x7C) = 0x32;
            obj[6]++;
        }
    }
}
