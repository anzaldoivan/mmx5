#include "types.h"

extern u8 D_8009A0A0[];
extern void (*D_8007717C[])(s8*);

void func_80049D40(s8* e) {
    s32 f;

    f = (s8)D_8009A0A0[0xD3] != 0;
    if ((s8)D_8009A0A0[0xD4] != 0) {
        f = 1;
    }
    if ((s8)D_8009A0A0[0x93] != 6) {
        f = 1;
    }
    if (f) {
        e[4] = 3;
    }
    e[0x15] = D_8009A0A0[0x15];
    D_8007717C[e[4]](e);
}
