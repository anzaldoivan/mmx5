#include "types.h"
#include "addr.h"

extern signed char D_8009A0A5;
extern u8 D_800D1C00[];

void func_800F9F20_ovl27(u8* a0) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        if ((*(s8**)(D_1F80004C.bytes + 0x80))[1] != 0x18) {
            p = D_800D1C00;
            p[0x2A] = 1;
            p[0x2B] = 0;
            a0[6]++;
        }
    }
}
