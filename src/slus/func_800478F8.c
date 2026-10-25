#include "types.h"

extern void func_800479F4(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

s32 func_800478F8(u8* a0) {
    s32 mask;

    mask = 2;
    if (a0[0x15] != 0) {
        mask = 1;
    }
    if (a0[0x8C] & mask) {
        func_800479F4(a0);
        func_8002D9EC(a0, 0x2C, 0x20);
        return 1;
    }
    return 0;
}
