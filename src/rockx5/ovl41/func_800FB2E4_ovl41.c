#include "types.h"

extern void func_800177B0(s32, s32);
extern u8 D_8009A2A3;

void func_800FB2E4_ovl41(u8* arg0) {
    D_8009A2A3 = 1;
    arg0[1]++;
    func_800177B0(0x10, 0x7F);
}
