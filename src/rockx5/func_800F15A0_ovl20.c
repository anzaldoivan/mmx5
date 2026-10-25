#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u16 D_800C9320;
extern u8 D_800D1C30;

void func_800F15A0_ovl20(u8* arg0) {
    if (D_800C9320 & 0x10) {
        func_80016490(5, 1, 0);
        arg0[1] = 7;
        arg0[2] = 2;
        D_800D1C30 = 1;
    }
}
