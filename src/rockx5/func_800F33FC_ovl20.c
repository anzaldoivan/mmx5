#include "types.h"

extern void (*D_800F5650_ovl20[])(u8*);

void func_800F33FC_ovl20(u8* arg0) {
    u16 x;
    u16 y;

    D_800F5650_ovl20[(signed char)arg0[6]](arg0);
    x = *(u16*)(arg0 + 0x38);
    y = *(u16*)(arg0 + 0x3A);
    *(s16*)(arg0 + 0x16) = -x;
    *(s16*)(arg0 + 0x2E) = -x;
    *(s16*)(arg0 + 0x1E) = x;
    *(s16*)(arg0 + 0x26) = x;
    *(s16*)(arg0 + 0x1A) = -y;
    *(s16*)(arg0 + 0x22) = -y;
    *(s16*)(arg0 + 0x2A) = y;
    *(s16*)(arg0 + 0x32) = y;
}
