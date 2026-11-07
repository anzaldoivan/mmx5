#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800D1C00[];
extern u8 D_80102AC8_ovl04[];

void func_800FEFCC_ovl04(u8* obj) {
    s32 t;

    t = *(s32*)(obj + 0x84) + 1;
    *(s32*)(obj + 0x84) = t;
    if (t > 300) {
        func_800171E8(obj, 0x14);
        obj[3] = 1;
        D_800D1C00[0x2A] &= 0xFE;
        obj[0x5C] = 0x10;
        *(u8**)(obj + 0x54) = D_80102AC8_ovl04;
        obj[5]--;
    } else if (t > 240) {
        if (t & 1) {
            func_800171E8(obj, 0x17);
        } else {
            func_800171E8(obj, 0x14);
        }
        obj[3] = 1;
    } else if (t > 180) {
        func_800171E8(obj, 0x17);
        if (*(s32*)(obj + 0x84) & 1) {
            obj[3] = 0;
        } else {
            obj[3] = 1;
        }
    }
}
