#include "types.h"

s32 func_8003979C(u8* arg0) {
    if (*(s8*)(arg0 + 0xD3) != 0) {
        return 0;
    }
    if (*(s8*)(arg0 + 0x87) == 0 && !(*(u16*)(arg0 + 0x80) & 0x100)) {
        return 0;
    }
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[0x15] = 0x40;
    }
    if (*(u16*)(arg0 + 0x7C) & 2) {
        arg0[0x15] = 0;
    }
    if (arg0[0x15] != 0) {
        if (arg0[0x89] & 1) {
            return 0;
        }
        *(s32*)(arg0 + 0x20) = *(s32*)(arg0 + 0x114);
    } else {
        if (arg0[0x89] & 2) {
            return 0;
        }
        *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x114);
    }
    return 1;
}
