#include "types.h"

extern s32 func_80044DE0(void);
extern void func_800FAD04_ovl27(u8* o, s32 a, s32 b);

void func_800FA050_ovl27(u8* o) {
    if (func_80044DE0() == 0) {
        func_800FAD04_ovl27(o, 4, 1);
        *(s16*)(o + 0x7C) = 2;
        o[6]++;
    }
}
