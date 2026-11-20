#include "types.h"

void func_800FD1EC_ovl38(u8* a0) {
    a0[0x47] = (*(u8**)(a0 + 0x7C))[0x47];
    if (--*(s16*)(a0 + 0x88) == 0) {
        *(s16*)(a0 + 0x88) = 4;
        *(s32*)(a0 + 0x50) = 0;
        a0[6]++;
    }
}
