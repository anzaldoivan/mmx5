#include "types.h"

extern void func_8003B33C(u8*, s32);

void func_80040FF4(u8* p) {
    if (*(s8*)(p + 0x46) == 0) {
        func_8003B33C(p, 0xAA);
        p[6]++;
    }
}
