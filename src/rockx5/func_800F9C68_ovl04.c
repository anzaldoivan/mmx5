#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800D1C00[];
extern u8 D_80102A94_ovl04[];
extern u8 D_80102A98_ovl04[];

void func_800F9C68_ovl04(u8* obj) {
    u8* g = D_800D1C00;
    s32 t;
    s8 k;

    g[0x28] &= ~obj[0x93];
    g[0x29] &= ~obj[0x93];
    t = *(s32*)(obj + 0x84) + 1;
    *(s32*)(obj + 0x84) = t;
    if (t >= 0x78) {
        k = obj[2];
        if (k == 5) {
            func_800171E8(obj, 3);
        } else if (k == 6) {
            func_800171E8(obj, 4);
        } else if (k == 7) {
            func_800171E8(obj, 5);
        } else if (k == 8) {
            func_800171E8(obj, 6);
        }
        obj[0x5C] = 0x10;
        *(u8**)(obj + 0x54) = D_80102A94_ovl04;
        *(u8**)(obj + 0x50) = D_80102A98_ovl04;
        obj[5] = 2;
        return;
    }
    if (t >= 0x3C) {
        if (t & 1) {
            k = obj[2];
            if (k == 5) {
                func_800171E8(obj, 3);
            } else if (k == 6) {
                func_800171E8(obj, 4);
            } else if (k == 7) {
                func_800171E8(obj, 5);
            } else if (k == 8) {
                func_800171E8(obj, 6);
            }
        } else {
            k = obj[2];
            if (k == 5) {
                func_800171E8(obj, 8);
            } else if (k == 6) {
                func_800171E8(obj, 0x34);
            } else if (k == 7) {
                func_800171E8(obj, 0x35);
            } else if (k == 8) {
                func_800171E8(obj, 0x36);
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
