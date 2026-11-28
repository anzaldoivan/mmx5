#include "types.h"

extern void (*D_80076FB4[])(u8*);

void func_80047044(u8* a0) {
    s8* p = *(s8**)(a0 + 0x7C);
    s32 f;

    f = p[0xD3] != 0;
    if (p[0xD4] != 0) {
        f = 1;
    }
    if (p[2] != 0) {
        if (p[0x93] != 1) {
            f = 1;
        }
    } else {
        if (p[0x93] != 2) {
            f = 1;
        }
    }
    if (((s8*)a0)[4] != 4) {
        if (f) {
            a0[4] = 3;
        }
    }
    D_80076FB4[((s8*)a0)[4]](a0);
}
