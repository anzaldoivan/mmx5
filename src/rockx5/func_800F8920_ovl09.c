#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FB2D0_ovl09[];
extern u8 D_800FB2DC_ovl09[];

void func_800F8920_ovl09(u8* obj) {
    func_800171E8(obj, 1);
    obj[0x62] = 2;
    obj[0x60] = 8;
    *(u8**)(obj + 0x50) = D_800FB2D0_ovl09;
    *(u8**)(obj + 0x68) = D_800FB2DC_ovl09;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = -0x20000;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x7C) = 0;
    obj[6]++;
}
