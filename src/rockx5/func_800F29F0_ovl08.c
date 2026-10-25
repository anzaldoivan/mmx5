#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F29F0_ovl08(u8* a0) {
    if (func_8002D938(a0, 0xA0, 0x50) == 0) {
        func_8002D9EC(a0, 0x70, 0x40);
    } else {
        a0[4] = 7;
    }
}
