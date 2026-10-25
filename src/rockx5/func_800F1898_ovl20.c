#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1C27;

void func_800F1898_ovl20(u8* arg0) {
    func_8002385C(0, 0xFF, 0);
    arg0[3] = 0;
    arg0[2]++;
    D_800D1C27 = 0x20;
}
