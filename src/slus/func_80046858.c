#include "types.h"

extern u8 D_8009A0A0[];
extern void (*D_80076FA8[])(s8*);

void func_80046858(s8* e) {
    s32 f;

    f = (s8)D_8009A0A0[0xD3] != 0;
    if ((s8)D_8009A0A0[0xD4] != 0) {
        f = 1;
    }
    if ((s8)D_8009A0A0[0x93] != 1) {
        f = 1;
    }
    if ((s8)D_8009A0A0[0xD5] != 0) {
        f = 1;
    }
    if (!(D_8009A0A0[0x5C] & 0x7F)) {
        f = 1;
    }
    if (f) {
        e[4] = 2;
    }
    D_80076FA8[e[4]](e);
}
