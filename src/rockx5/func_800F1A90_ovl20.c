#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1C27;

void func_800F1A90_ovl20(u8* o) {
    func_8002385C(7, 0xFF, 0);
    o[3] = 0;
    o[2]++;
    D_800D1C27 = 0x20;
}
