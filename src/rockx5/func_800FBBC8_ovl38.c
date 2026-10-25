#include "types.h"

extern void func_800171E8(u8*, s32);
extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1C00[];

void func_800FBBC8_ovl38(u8* obj) {
    func_800171E8(obj, 1);
    func_8002385C(0x48, 0xFF, D_800D1C00[0x2E]);
    D_800D1C00[0x2E] = 1;
    obj[6]++;
}
