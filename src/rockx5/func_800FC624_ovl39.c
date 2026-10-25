#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1C00[];

void func_800FC624_ovl39(u8* obj) {
    u8* p = D_800D1C00;
    func_8002385C(0x54, 0xFF, p[0x30]);
    p[0x30] = 1;
    obj[6]++;
}
