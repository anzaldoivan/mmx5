#include "types.h"

extern void func_800EFC40_ovl01();

void func_800EFBB4_ovl01(u8* p) {
    p[0x19]++;
    p[0x18] = (p[0x18] + 1) & 3;
    if (p[0x18] == 0) {
        func_800EFC40_ovl01();
    }
    if (p[0x19] > 120) {
        p[4]++;
    }
}
