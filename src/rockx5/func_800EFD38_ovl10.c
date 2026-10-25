#include "types.h"

void func_800EFD38_ovl10(u8* a0) {
    if (*(s16*)(a0 + 0x7C) != 0) {
        *(s16*)(a0 + 0x7C) -= 1;
        return;
    }
    a0[6]++;
}
