#include "types.h"

extern u8 D_800D1C00[];

s32 func_8002DC14(void) {
    u8* p = D_800D1C00;

    if (p[0x79] >= 5) {
        return 2;
    }
    return p[0xCB] & 1;
}
