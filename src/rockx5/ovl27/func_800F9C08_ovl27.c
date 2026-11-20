#include "types.h"
#include "addr.h"

extern void (*D_800FDA7C_ovl27[])(u8*);
extern u8 D_8009A11A;

void func_800F9C08_ovl27(u8* a0) {
    u8* p;

    D_1F80004C.bytes[0x8D] = a0[5];
    D_800FDA7C_ovl27[(s8)a0[5]](a0);
    if ((s8)a0[5] != 2) {
        p = D_1F80004C.bytes;
        a0[0x5C] = p[0x87] + (p[0x85] + (p[0x84] + p[0x86]));
        if (((s8*)a0)[0x5C] == 0) {
            D_8009A11A = 1;
            a0[4] = 2;
            a0[5] = 0;
        }
    }
}
