#include "types.h"

extern u8 D_8009A19A;

s32 func_80031508(u8* a0, u8 a1) {
    switch (a1) {
    case 0x38:
    case 0x3A:
    case 0x3C:
        a0[0x4A] = 1;
        return -1;
    case 0x39:
        a0[0x4A] = 0;
        return -1;
    case 0x3E:
    case 0x3F:
        if (D_8009A19A == 3) {
            a0[0x4A] = 1;
        } else {
            a0[0x4A] = 0;
            a0[0x79] = 1;
        }
        return -1;
    }
    return 0;
}
