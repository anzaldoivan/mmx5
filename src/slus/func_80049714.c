#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void (*D_80077114[])(u8*);

void func_80049714(u8* p) {
    if (func_8002D938(p, 0x30, 0x30) == 0 && *(s8*)(p + 0x98) == 0) {
        D_80077114[p[0x8E] - 1](p);
    } else {
        p[4] = 2;
    }
}
