#include "types.h"

extern s16 D_8009A0AA;

s32 func_800F2FEC_ovl01(u8* obj) {
    s32 x = D_8009A0AA;
    s32 y = *(s16*)(obj + 0xA);

    if (((x - y) < 0 ? (y - x) : (x - y)) < 0x60) {
        obj[6] = 3;
        return 1;
    }
    return 0;
}
