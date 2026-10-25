#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern u8 D_8009A0B5;

void func_800F9CF0_ovl27(u8* arg0) {
    func_8003D29C(0x14, D_8009A0B5);
    arg0[5]++;
}
