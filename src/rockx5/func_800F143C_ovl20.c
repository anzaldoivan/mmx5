#include "types.h"

extern u8 D_8009A1F8[];

void func_800F143C_ovl20(u8* arg0) {
    u8* b;
    u8* c;
    u16 v;

    b = D_8009A1F8;
    if (*(s16*)(b + 0x5E) < 0x141) {
        *(s16*)(b + 0x5E) -= 8;
    } else {
        *(s16*)(b + 0x5E) += 8;
    }
    c = D_8009A1F8;
    v = *(u16*)(c + 0x5E);
    if (v == 0 || v >= 0x3C0) {
        *(s16*)(c + 0x5E) = 0x3C0;
        c[0xA0] = 1;
        arg0[2]++;
    }
}
