#include "types.h"

extern s32 func_800306E0(u8* a0);

s32 func_80030CBC(u8* obj) {
    s32 r = func_800306E0(obj);

    switch (r) {
    case 0x28:
    case 0x29:
    case 0x2D:
        if (*(s16*)(obj + 0x6E) >= 8) {
            r = 0;
        }
        break;
    case 0x27:
    case 0x2A:
        if (*(s16*)(obj + 0x6E) < 2 || *(s16*)(obj + 0x6E) > 10) {
            r = 0;
        }
        break;
    case 0x26:
    case 0x2B:
        if (*(s16*)(obj + 0x6E) < 6 || *(s16*)(obj + 0x6E) > 14) {
            r = 0;
        }
        break;
    case 0x25:
    case 0x2C:
        if (*(s16*)(obj + 0x6E) < 8) {
            r = 0;
        }
        break;
    }
    return r;
}
