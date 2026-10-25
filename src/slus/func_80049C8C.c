#include "types.h"

extern u8 D_8009A0A0[];
extern void (*D_8007716C[])(s8*);

void func_80049C8C(s8* e) {
    s32 f;

    f = (s8)D_8009A0A0[0xD3] != 0;
    if ((s8)D_8009A0A0[0xD4] != 0) {
        f = 1;
    }
    if ((s8)D_8009A0A0[0x93] != 6) {
        f = 1;
    }
    if ((s8)D_8009A0A0[0x96] == 0xF) {
        f = 1;
    }
    if (e[2] != 2 && (s8)D_8009A0A0[0x5] != 0x2A) {
        f = 1;
    }
    if (f) {
        e[4] = 3;
    }
    D_8007716C[e[4]](e);
}
