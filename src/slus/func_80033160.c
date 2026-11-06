#include "types.h"

void func_80033160(u8* a, u8* b) {
    s32 d;
    s32 m;
    s16 t;
    s16 u;

    d = *(s16*)(a + 0xA) - *(s16*)(a + 0x1A);
    if (d != 0) {
        if (d > 0) {
            m = b[0x70] & 1;
        } else {
            m = b[0x70] & 2;
        }
        if (m == 0) {
            t = *(u16*)(b + 0xA) - *(u16*)(b + 0x1A);
            u = *(u16*)(a + 0x1A) - *(u16*)(b + 0x1A);
            *(s16*)(b + 0xA) = t + (*(u16*)(a + 0xA) - u);
        }
    }
    if (*(s16*)(a + 0xE) - *(s16*)(a + 0x1E) > 0) {
        t = *(u16*)(b + 0xE) - *(u16*)(b + 0x1E);
        u = *(u16*)(a + 0x1E) - *(u16*)(b + 0x1E);
        *(s16*)(b + 0xE) = t + (*(u16*)(a + 0xE) - u);
    }
}
