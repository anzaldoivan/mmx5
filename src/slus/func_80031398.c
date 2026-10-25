#include "types.h"

extern u8 D_8009A19A;

s32 func_80031398(u8* obj, u8 code, s32 mode) {
    if (mode == 0) {
        switch (code) {
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3C:
            return -1;
        case 0x3E:
        case 0x3F:
            goto set_flag; // !FAKE: goto kept for the matching branch layout
        }
        return 0;
    }
    switch (code) {
    case 0x21:
    case 0x22:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3C:
        return -1;
    case 0x3E:
    case 0x3F:
    set_flag:
        if (D_8009A19A != 3) {
            obj[0x79] = 1;
        }
        return -1;
    }
    return 0;
}
