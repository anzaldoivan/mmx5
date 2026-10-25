#include "types.h"

extern u16 D_800C9320;
extern u8 D_800D1F28[];
extern void func_80016490(s32, s32, void*);
extern s32 func_8002C50C(void);

void func_8001DDF4(void) {
    if (D_800C9320 & 0x40) {
        func_80016490(0, 0x22, 0);
        func_8002C50C();
        D_800D1F28[0] = 7;
        D_800D1F28[1] = 5;
    }
}
