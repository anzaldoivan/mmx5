#include "types.h"

extern int func_8002D6FC();
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s8 D_800D1C30;

void func_800F48C8_ovl20(u8* a0) {
    if (D_800D1C30 != 0) {
        func_8002D6FC();
    } else {
        func_8002D9EC(a0, 0x80, 0x40);
    }
}
