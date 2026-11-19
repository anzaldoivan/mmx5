#include "types.h"
#include "addr.h"

void func_800FB8D8_ovl38(u8* a0) {
    a0[0x47] = (*(u8**)(D_1F80004C.bytes + 0x80))[0x47];
    if (*(u16*)(a0 + 0x7C) & 1) {
        a0[3] = 1;
    } else {
        a0[3] = 0;
    }
    if (--*(s16*)(a0 + 0x7C) == 0 || (u8)(a0[0x47] - 2) >= 2) {
        a0[3] = 0;
        a0[4]++;
    }
}
