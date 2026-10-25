#include "types.h"

extern void func_8003D29C(s32, s32);
extern u8 D_8009A175;

void func_800F0D8C_ovl07(u8* arg0) {
    *(s32*)(arg0 + 0x20) = 0xA0000;
    *(s32*)(arg0 + 0x24) = 0;
    arg0[5]++;
    D_8009A175 = 0;
    func_8003D29C(0x17, 0x40);
}
