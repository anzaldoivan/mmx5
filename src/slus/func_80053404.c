#include "types.h"

void func_80053404(u8* a0) {
    if (*(s8*)(a0 + 0x45) != 0) {
        if (a0[0x84] == 0) {
            a0[0x15] = 0;
        } else {
            a0[0x15] = 0x40;
        }
        a0[0x5] = 4;
        a0[0x6] = 0;
    }
}
