#include "types.h"

void func_800FDB74_ovl39(u8* a0) {
    if (*(s8*)(*(u8**)(a0 + 0x7C) + 7) != 0x11) {
        a0[0x84] = 0;
        a0[4] = 2;
    }
    if ((*(u8**)(a0 + 0x7C))[0x89] == 3) {
        a0[6]++;
    }
}
