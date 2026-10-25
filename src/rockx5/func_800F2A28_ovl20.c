#include "types.h"

extern int func_8002D6FC();
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800D1C78[];

void func_800F2A28_ovl20(u8* a0) {
    if (D_800D1C78[1] >= 5) {
        func_8002D6FC();
    } else {
        func_8002D9EC(a0, 0x40, 0x40);
    }
}
