#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FE4DC_ovl06[];
extern u8 D_800FE4E0_ovl06[];

void func_800F4888_ovl06(u8* obj) {
    *(s32*)(obj + 0x20) = 0xFFFD0000;
    *(s32*)(obj + 0x28) = 0x3000;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x8D] = 1;
    obj[0x6]++;
    func_800171E8(obj, 1);
    *(u8**)(obj + 0x50) = D_800FE4DC_ovl06;
    *(u8**)(obj + 0x54) = D_800FE4E0_ovl06;
}
