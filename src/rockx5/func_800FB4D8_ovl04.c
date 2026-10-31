#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800D1C00[];
extern u8 D_80102AB4_ovl04[];
extern u8 D_80102AB8_ovl04[];

void func_800FB4D8_ovl04(u8* obj) {
    u8* g = D_800D1C00;
    s32 t;
    s8 k;

    g[0x28] &= ~obj[0x93];
    g[0x29] &= ~obj[0x93];
    t = *(s32*)(obj + 0x84) + 1;
    *(s32*)(obj + 0x84) = t;
    if (t >= 0x78) {
        k = obj[2];
        if (k == 12) {
            func_800171E8(obj, 0xD);
        } else if (k == 13) {
            func_800171E8(obj, 0xE);
        } else if (k == 14) {
            func_800171E8(obj, 0xF);
        } else if (k == 15) {
            func_800171E8(obj, 0x10);
        }
        obj[0x5C] = 0x10;
        *(u8**)(obj + 0x54) = D_80102AB4_ovl04;
        *(u8**)(obj + 0x50) = D_80102AB8_ovl04;
        obj[5] = 2;
        return;
    }
    if (t >= 0x3C) {
        if (t & 1) {
            k = obj[2];
            if (k == 12) {
                func_800171E8(obj, 0xD);
            } else if (k == 13) {
                func_800171E8(obj, 0xE);
            } else if (k == 14) {
                func_800171E8(obj, 0xF);
            } else if (k == 15) {
                func_800171E8(obj, 0x10);
            }
        } else {
            k = obj[2];
            if (k == 12) {
                func_800171E8(obj, 0x11);
            } else if (k == 13) {
                func_800171E8(obj, 0x37);
            } else if (k == 14) {
                func_800171E8(obj, 0x38);
            } else if (k == 15) {
                func_800171E8(obj, 0x39);
            }
        }
        obj[3] = 1;
        return;
    }
    if (t & 1) {
        obj[3] = 0;
        return;
    }
    obj[3] = 1;
}
