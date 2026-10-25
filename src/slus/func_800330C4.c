#include "types.h"

void func_800330C4(u8* a, u8* b) {
    s16 d;
    s16 e;

    if (*(s16*)(a + 0xA) != *(s16*)(a + 0x1A)) {
        d = *(s16*)(b + 0xA) - *(s16*)(b + 0x1A);
        e = *(s16*)(a + 0x1A) - *(s16*)(b + 0x1A);
        *(s16*)(b + 0xA) = d + (*(s16*)(a + 0xA) - e);
    }
    if (*(s16*)(a + 0xE) - *(s16*)(a + 0x1E) > 0) {
        d = *(s16*)(b + 0xE) - *(s16*)(b + 0x1E);
        e = *(s16*)(a + 0x1E) - *(s16*)(b + 0x1E);
        *(s16*)(b + 0xE) = d + (*(s16*)(a + 0xE) - e);
    }
}
