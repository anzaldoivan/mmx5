#include "types.h"

extern u8* func_8002C938();

void func_800F6EE8_ovl01(void) {
    u8* p;

    p = func_8002C938();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x10;
        p[2] = 0x70;
    }
}
