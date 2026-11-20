#include "types.h"

void func_800F1D38_ovl08(u8* p) {
    if (*(s8*)(p + 6) == 0) {
        p[6]++;
        *(s16*)(p + 0x7C) = *(s16*)(p + 0x82) + 0xB4;
    } else if (*(s8*)(p + 4) == 1) {
        if (--*(s16*)(p + 0x7C) == 0) {
            *(s16*)(p + 0x82) = 0;
            p[5] = 1;
            p[6] = 0;
        }
    }
}
