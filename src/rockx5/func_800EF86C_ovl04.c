#include "types.h"

extern void func_8003D2C4(void);
extern void func_8003D29C(s32, s32);
extern s16 D_8009A202;
extern s8 D_800D1C1D;

void func_800EF86C_ovl04(u8* a0) {
    if (D_8009A202 >= 0x230) {
        func_8003D2C4();
        func_8003D29C(0x14, 0);
        D_800D1C1D = 1;
        a0[6] = 0;
        a0[5]++;
    }
}
