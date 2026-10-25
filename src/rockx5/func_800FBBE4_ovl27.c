#include "types.h"

extern void* D_800FDC04_ovl27[];

void func_800FBBE4_ovl27(u8* a0) {
    u8* p = *(u8**)(a0 + 0x7C);

    if (!(p[0x8C] & 1)) {
        p[0x8A] = 2;
        a0[5] = 3;
        a0[6] = 0;
    } else {
        ((void (*)(u8*))D_800FDC04_ovl27[(s8)a0[6]])(a0);
    }
}
