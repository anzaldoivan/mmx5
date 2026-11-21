#include "types.h"
#include "addr.h"

extern s8 D_8009A1F6;

void func_800F5A88_ovl27(void) {
    if (D_8009A1F6 != 0) {
        D_1F80004C.bytes[0x87] = 1;
    }
}
