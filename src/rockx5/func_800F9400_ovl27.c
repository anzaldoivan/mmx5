#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_800FB308_ovl27(u8* o, u8 arg1);
extern u8 D_800FDB5C_ovl27[];
extern u8 D_800FDB64_ovl27[];
extern u8 D_80074DA0[];
extern u8 D_800FDB68_ovl27[];
extern u8 D_800FDB6C_ovl27[];
extern u8 D_800FDB70_ovl27[];
extern u8 D_8009A0A0[];
extern u8 D_800767E0[];
extern u8 D_800FDB74_ovl27[];
extern s8 D_8009A0A2;
extern u8 D_800D1C49;
extern u8 D_800FDB7C_ovl27[];
extern u8 D_800FDB80_ovl27[];
extern u8 D_800FDB88_ovl27[];
extern u8 D_800FDB94_ovl27[];

void func_800F9400_ovl27(u8* obj) {
    s32 angle;
    u8* p;
    s32 dx;
    s32 dy;
    s32 t;
    s32 u;

    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    obj[0x16] = 1;
    obj[0x15] = 0;
    obj[3] = 1;
    switch ((s8)obj[2]) {
    case 0:
        func_800171E8(obj, 7);
        t = 6;
        obj[0x60] = t;
        t = (s32)D_800FDB5C_ovl27;
        *(s32*)(obj + 0x68) = t;
        t = (s32)D_800FDB64_ovl27;
        obj[0x5C] = 0;
        *(s32*)(obj + 0x58) = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = t;
        obj[6] = 0;
        *(s16*)(obj + 0x88) = 0;
        break;
    case 1:
        func_800171E8(obj, 0x10);
        obj[0x5C] = 1;
        obj[0x60] = 6;
        *(u8**)(obj + 0x58) = D_80074DA0;
        *(u8**)(obj + 0x68) = D_800FDB68_ovl27;
        *(u8**)(obj + 0x54) = D_800FDB6C_ovl27;
        *(u8**)(obj + 0x50) = D_800FDB70_ovl27;
        p = D_8009A0A0;
        dx = *(s16*)(p + 0xA);
        dy = *(s16*)(p + 0xE);
        angle = ratan2(*(s16*)(obj + 0xE) - dy, dx - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = rcos(angle) << 4;
        *(s32*)(obj + 0x24) = rsin(angle) << 4;
        if (*(s32*)(obj + 0x20) != 0) {
            *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 5;
        } else {
            *(s32*)(obj + 0x20) = 0;
        }
        if (*(s32*)(obj + 0x24) != 0) {
            *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) * 5;
        } else {
            *(s32*)(obj + 0x24) = 0;
        }
        if (*(s32*)(obj + 0x20) < 0) {
            obj[0x15] = 0;
        } else {
            obj[0x15] = 0x40;
        }
        *(s16*)(obj + 0x88) = 4;
        obj[6] = 0;
        break;
    case 2:
        obj[0x16] = 7;
        func_800171E8(obj, 3);
        u = 0x7F;
        t = (s32)D_800767E0;
        *(s32*)(obj + 0x58) = t;
        t = (s32)D_800FDB74_ovl27;
        *(s32*)(obj + 0x54) = t;
        t = 0x4000;
        *(s32*)(obj + 0x20) = t;
        t = 0x40;
        obj[0x60] = u;
        u = 1;
        *(s16*)(obj + 0x88) = t;
        obj[0x5C] = 0;
        *(s32*)(obj + 0x68) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x24) = 0;
        obj[6] = u;
        if (D_8009A0A2 == 0 && D_800D1C49 == 3) {
            *(u8**)(obj + 0x68) = D_800FDB7C_ovl27;
            func_800FB308_ovl27(obj, 2);
        }
        break;
    case 3:
        obj[0x16] = 7;
        func_800171E8(obj, 2);
        u = 0x7F;
        t = (s32)D_800767E0;
        *(s32*)(obj + 0x58) = t;
        t = (s32)D_800FDB80_ovl27;
        *(s32*)(obj + 0x54) = t;
        t = -0x4000;
        *(s32*)(obj + 0x20) = t;
        t = 0x40;
        obj[0x60] = u;
        u = 1;
        *(s16*)(obj + 0x88) = t;
        obj[0x5C] = 0;
        *(s32*)(obj + 0x68) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x24) = 0;
        obj[6] = u;
        if (D_8009A0A2 == 0 && D_800D1C49 == 3) {
            *(u8**)(obj + 0x68) = D_800FDB88_ovl27;
            func_800FB308_ovl27(obj, 2);
        }
        break;
    case 4:
        obj[0x16] = 7;
        func_800171E8(obj, 0x14);
        u = 0x7F;
        t = (s32)D_800767E0;
        *(s32*)(obj + 0x58) = t;
        t = 0x1E;
        obj[0x60] = u;
        u = 4;
        *(s16*)(obj + 0x88) = t;
        obj[0x5C] = 0;
        *(s32*)(obj + 0x68) = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        obj[6] = u;
        if (D_8009A0A2 == 0 && D_800D1C49 == 3) {
            *(u8**)(obj + 0x68) = D_800FDB94_ovl27;
            func_800FB308_ovl27(obj, 3);
        }
        break;
    }
    obj[5] = 1;
    obj[7] = 0;
    obj[4]++;
}
