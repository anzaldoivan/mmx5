#include "types.h"

extern u8 D_8009A0A0[];

void func_8004A70C(u8* e) {
    u8* p = D_8009A0A0;

    *(s16*)(e + 0xA) = *(s16*)(p + 0xA);
    *(s16*)(e + 0xE) = *(s16*)(p + 0xE);
    if (*(s8*)(e + 0x46) == 0) {
        e[3] = 0;
        e[4] = 3;
    }
}
