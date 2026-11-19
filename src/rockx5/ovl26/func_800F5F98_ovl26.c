#include "types.h"

void func_800F5F98_ovl26(u8* a0) {
    if (*(s16*)(a0 + 0x90) != 0) {
        *(s16*)(a0 + 0x90) -= 1;
        return;
    }
    a0[6]++;
}
