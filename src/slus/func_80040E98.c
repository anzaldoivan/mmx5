#include "types.h"

s32 func_80040E98(u8* a0) {
    s32 m;

    if (a0[0x89] & 4) {
        *(s32*)(a0 + 0x24) = 0;
        *(s32*)(a0 + 0x2C) = 0;
    }
    m = 2;
    if (a0[0x15] != 0) {
        m = 1;
    }
    if (a0[0x89] & m) {
        *(s32*)(a0 + 0x20) = 0;
        *(s32*)(a0 + 0x28) = 0;
        return 1;
    }
    return 0;
}
