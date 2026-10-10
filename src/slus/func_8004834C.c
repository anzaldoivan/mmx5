#include "types.h"

extern u8 D_8009A0A0[];
extern void (*D_800770A0[])(s8*);

void func_8004834C(s8* e) {
    s32 f;

    ((s32*)e)[6] = ((s32*)e)[2];
    ((s32*)e)[7] = ((s32*)e)[3];
    f = (s8)D_8009A0A0[0xD3] != 0;
    if ((s8)D_8009A0A0[0xD4] != 0) {
        f = 1;
    }
    if ((s8)D_8009A0A0[0x93] != 4) {
        f = 1;
    }
    if (f) {
        e[4] = 2;
    }
    D_800770A0[e[4]](e);
}
