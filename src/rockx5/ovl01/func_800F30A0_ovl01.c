#include "types.h"
#include "addr.h"

s32 func_800F30A0_ovl01(void) {
    u8* p = D_1F80004C.bytes;

    if (p[0x83] != 0) {
        p[0x83]--;
        return 0;
    }
    if (p[0x82] != 0) {
        p[0x82]--;
        p = D_1F80004C.bytes;
        if (p[0x82] == 0) {
            p[0x83] = 4;
        }
    } else {
        if (*(s32*)(p + 0x84) <= 0) {
            goto none; // !FAKE: goto kept for the matching branch layout
        }
        p[0x82] = 8;
    }
    return 1;
none:
    return 0;
}
