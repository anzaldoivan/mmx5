#include "types.h"

extern u8 D_800D1C00[];

void func_8002CF20(void) {
    u8* p;
    s32 n;
    u8 z;

    z = 0;
    p = D_800D1C00;
    n = 0x1BB;
    do {
        *p++ = z;
    } while (n--);
}
