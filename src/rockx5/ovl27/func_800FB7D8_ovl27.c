#include "types.h"

void func_800FB7D8_ovl27(u8* a0) {
    if (*(u16*)(a0 + 0x88) & 1) {
        a0[3] = 0;
    } else {
        a0[3] = 1;
    }
    if (--*(s16*)(a0 + 0x88) == 0) {
        a0[3] = 0;
        a0[4]++;
    }
}
