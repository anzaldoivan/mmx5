#include "types.h"

extern int func_8002D6FC();
extern void (*D_800F5A90_ovl20[])(u8*);
extern s8 D_800D1C30;

void func_800F4D20_ovl20(u8* a0) {
    D_800F5A90_ovl20[(s8)a0[4]](a0);
    if ((s8)a0[2] >= 8 && D_800D1C30 != 0) {
        func_8002D6FC(a0);
    }
}
