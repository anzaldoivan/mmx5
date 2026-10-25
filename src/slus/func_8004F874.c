#include "types.h"

extern u8 D_8009A0A0[];
extern int func_80045D44();

void func_8004F874(u8* a0) {
    u8* p;

    if (((s8*)a0)[0x5C] == 0) {
        p = D_8009A0A0;
        if (((s8*)p)[0x8E] == 0) {
            a0[0x5C] = 1;
        }
        if (p[0x15] != a0[0x15]) {
            a0[0x5C] = 1;
        }
        if (((s8*)a0)[0x5C] == 0) {
            func_80045D44(a0, p, ((s8*)a0)[2]);
        }
    }
}
