#include "types.h"
#include "addr.h"

s32 func_800F3040_ovl01(u8* a0) {
    s32 t;

    if (a0[0x15] != 0) {
        goto alt; // !FAKE: goto kept for the matching branch layout
    }
    t = a0[0x70] & 2;
test:
    if (t == 0) {
        goto zero; // !FAKE: goto kept for the matching branch layout
    }
    a0[6] = 4;
    D_1F80004C.bytes[0x80] = 0x1E;
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x28) = 0;
    return 1;
alt:
    t = a0[0x70] & 1;
    goto test; // !FAKE: goto kept for the matching branch layout
zero:
    return 0;
}
