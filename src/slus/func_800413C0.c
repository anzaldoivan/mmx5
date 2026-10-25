#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8003B33C(u8*, s32);

void func_800413C0(u8* a0) {
    if (*(s8*)(a0 + 0x45) == 2) {
        func_80016490(1, 0xE, a0);
        *(s8*)(a0 + 0x45) = 0;
    }
    if (*(s8*)(a0 + 0x45) != 0) {
        a0[0xF4]++;
    }
    if (a0[0xF4] >= 0x33) {
        func_80016490(1, 0xF, a0);
        func_8003B33C(a0, 0xB5);
        a0[0xF4] = 0;
        a0[6]++;
    }
}
