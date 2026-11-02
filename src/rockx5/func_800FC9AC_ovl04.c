#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800D1C00[];
extern u8 D_80102ACC_ovl04[];

void func_800FC9AC_ovl04(u8* obj) {
    s32 t;

    D_800D1C00[0x28] &= ~obj[0x93];
    t = *(s32*)(obj + 0x84) + 1;
    *(s32*)(obj + 0x84) = t;
    if (t >= 0x78) {
        if (((s8*)obj)[2] == 0x14) {
            func_800171E8(obj, 0x18);
        } else if (((s8*)obj)[2] == 0x15) {
            func_800171E8(obj, 0x19);
        } else if (((s8*)obj)[2] == 0x16) {
            func_800171E8(obj, 0x1A);
        } else if (((s8*)obj)[2] == 0x17) {
            func_800171E8(obj, 0x1B);
        }
        obj[0x5C] = 0x10;
        *(u8**)(obj + 0x54) = D_80102ACC_ovl04;
        obj[5] = 2;
        return;
    }
    if (t >= 0x3C) {
        if (t & 1) {
            if (((s8*)obj)[2] == 0x14) {
                func_800171E8(obj, 0x18);
            } else if (((s8*)obj)[2] == 0x15) {
                func_800171E8(obj, 0x19);
            } else if (((s8*)obj)[2] == 0x16) {
                func_800171E8(obj, 0x1A);
            } else if (((s8*)obj)[2] == 0x17) {
                func_800171E8(obj, 0x1B);
            }
        } else {
            func_800171E8(obj, 0x1C);
        }
    } else if (t & 1) {
        obj[3] = 0;
        return;
    }
    obj[3] = 1;
}
