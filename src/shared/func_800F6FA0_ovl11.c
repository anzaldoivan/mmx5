/* Shared body (DK-5), from the banked draft of func_800F6FA0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_800F81F4_ovl11(u8* obj);
extern u8 D_8009A0A0[];
extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void DEDUP_NAME(u8* obj) {
    u8* p;
    s16 x;

    func_800171E8(obj, 5);
    func_80017248(obj);
    obj[0x60] = 8;
    p = D_8009A0A0;
    if (((s8*)p)[2] == 0 && p[0xFA] == 0) {
        obj[0x62] = 8;
    } else {
        obj[0x62] = 6;
    }
    func_800F81F4_ovl11(obj);
    x = *(s16*)(obj + 0xA);
    if (x < D_800FA056_ovl11) {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 1;
    } else if (D_800FA058_ovl11 < x) {
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = -1;
    }
    *(s32*)(obj + 0x28) = -0x3333;
    *(s16*)(obj + 0x7C) = 8;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x20) <<= 18;
    obj[6]++;
}
