#include "types.h"

s32 func_800395E8(u8* arg0) {
    u16 flags;

    if (*(s8*)(arg0 + 0xD3) != 0) {
        return 0;
    }
    flags = *(u16*)(arg0 + 0x7C);
    if (!(flags & 3)) {
        return 0;
    }
    if (flags & 1) {
        arg0[0x15] = 0x40;
        if (arg0[0x89] & 1) {
            return 0;
        }
        *(s32*)(arg0 + 0x20) = *(s32*)(arg0 + 0x100);
    } else {
        arg0[0x15] = 0;
        if (arg0[0x89] & 2) {
            return 0;
        }
        *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x100);
    }
    return 1;
}
