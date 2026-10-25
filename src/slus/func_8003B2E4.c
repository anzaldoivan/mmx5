#include "types.h"

extern s32 func_80039ECC(u8* arg0);
extern void func_8003B33C(u8*, s32);

void func_8003B2E4(u8* p) {
    if (func_80039ECC(p) == 0) {
        func_8003B33C(p, (*(s32*)(p + 0x8C) & 0xFFFF0000) ? 0x6D : 0x51);
        p[0x5] = 0x1A;
        p[0x6] = 0;
    }
}
