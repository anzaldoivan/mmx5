/* Shared body (DK-5), from the banked draft of func_800EFD00_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800F0978_ovl29(u8* obj);
extern u8 D_800750C0[];
extern u8 D_8009A0B4;
extern u8 D_800F91A8_ovl29[];
extern u8 D_800F91AC_ovl29[];
extern u8 D_800F91B0_ovl29[];
extern u8 D_800F9304_ovl29[];

void DEDUP_NAME(u8* obj) {
    s8 v;
    u8 b;
    s32 x;
    s32 y;

    obj[0x5C] = 9;
    *(s32*)(obj + 0x80) = 0;
    *(s32*)(obj + 0x84) = 0;
    *(s32*)(obj + 0x88) = 0;
    *(s32*)(obj + 0x8C) = 0;
    *(s32*)(obj + 0x90) = 0;
    *(s32*)(obj + 0x94) = 0;
    obj[0x60] = 3;
    obj[0x61] = 0;
    *(u8**)(obj + 0x58) = D_800750C0;
    b = D_8009A0B4;
    *(u8**)(obj + 0x30) = D_800F9304_ovl29;
    obj[0x16] = 6;
    *(u8**)(obj + 0x68) = D_800F91B0_ovl29;
    *(u8**)(obj + 0x54) = D_800F91A8_ovl29;
    x = *(s32*)(obj + 0x8);
    y = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x50) = D_800F91AC_ovl29;
    obj[0x14] = b;
    *(s32*)(obj + 0x18) = x;
    *(s32*)(obj + 0x1C) = y;
    func_800F0978_ovl29(obj);
    v = (s8)obj[2];
    switch (v) {
    case 0:
        obj[0x80] = 0;
        obj[0x8C] = 0;
        *(s16*)(obj + 0x7C) = 0x5A;
        obj[4] = 1;
        obj[5] = 3;
        obj[6] = 0;
        break;
    case 1:
        *(s16*)(obj + 0x7C) = 0xA;
        obj[0x80] = 0;
        obj[0x8C] = 0;
        obj[4] = v;
        obj[5] = 5;
        obj[6] = 0;
        break;
    }
    func_800171E8(obj, 0x14);
}
