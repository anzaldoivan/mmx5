#include "types.h"

void func_8002EBEC(u8* a, u8* b) {
    u8* pa = *(u8**)(a + 0x68);
    u8* pb = *(u8**)(b + 0x68);
    s16 xa = *(s16*)(a + 0xE) + ((s8*)pa)[1];
    s16 xb = *(s16*)(b + 0xE) + ((s8*)pb)[1];

    if (*(s8*)(a + 0x66) == -2) {
        xa = xa - pa[3];
        xb = pb[3] + xb;
    } else if (*(s8*)(a + 0x66) != -3 && xb < xa) {
        xa = xa - pa[3];
        xb = pb[3] + xb;
    } else {
        xa = pa[3] + xa;
        xb = xb - pb[3];
    }
    *(s16*)(b + 0x6E) = xa - xb;
}
