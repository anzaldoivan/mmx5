#include "types.h"

extern u8 D_8009A1F8[];

void func_800FB6AC_ovl56(u8* e) {
    u8* p;

    if (*(s16*)(e + 6) < 0x5B) {
        *(s16*)(e + 6) += 1;
        return;
    }
    p = D_8009A1F8;
    p[0xA0] = 1;
    *(s32*)(p + 0x60) += 0x2D82D;
    *(s16*)(e + 4) += 1;
    if (*(s16*)(e + 4) >= 0x5A) {
        e[1]++;
    }
}
