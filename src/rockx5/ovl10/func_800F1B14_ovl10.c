#include "types.h"

void func_800F1B14_ovl10(u8* o) {
    if (*(s8*)(o + 0x45) == 2) {
        o[5] = 3;
        o[6] = 0;
    }
}
