#include "types.h"

extern u8 D_8009A1F8[];

void func_800F1670_ovl07(u8* arg0) {
    u8* p = D_8009A1F8;

    if (*(s16*)(p + 0xA) == 0x1E00) {
        *(s16*)(p + 0xB2) = 0x1E00;
        *(s16*)(p + 0xB6) = 0;
        p[0xAC] = 1;
        *(s16*)(p + 0xE8) = 0xC80;
        *(s16*)(p + 0xEA) = 0xF0;
        p[0xF4] = 1;
        arg0[4]++;
    }
}
