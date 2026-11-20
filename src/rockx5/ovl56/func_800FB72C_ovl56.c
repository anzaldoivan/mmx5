#include "types.h"

extern u8 D_800D1F3C;
extern void func_800177B0(s32, s32);

void func_800FB72C_ovl56(u8* arg0) {
    if (D_800D1F3C == 0) {
        func_800177B0(0x13, 0x7F);
        arg0[1]++;
    }
}
