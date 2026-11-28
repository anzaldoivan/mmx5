#include "types.h"

s32 func_80031630(u8 arg0) {
    switch (arg0) {
    case 3 ... 6:
    case 10:
    case 11:
    case 16:
    case 56 ... 58:
    case 60:
    case 62:
    case 63:
        return 1;
    default:
        return 0;
    }
}
