#include "types.h"

extern void* func_8003D3A8(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern void func_8003B33C(u8*, s32);

void func_8004145C(u8* a0) {
    if (*(s8*)(a0 + 0x45) != 0) {
        a0[0xF4]++;
    }
    if (*(s8*)(a0 + 0x45) & 0x80) {
        a0[0x45] &= 0x7F;
        func_8003D3A8(1, 0x2F, 0, 0);
    }
    if (a0[0xF4] >= 0x79) {
        a0[6]++;
        func_8003B33C(a0, 0xB6);
    }
}
