#include "types.h"

extern u8 D_8009A1F8[];

void func_800F1308_ovl07(u8* arg0) {
    u8* p = D_8009A1F8;

    if (*(s8*)(p + 4) == 1) {
        *(s16*)(arg0 + 0xA) += *(s16*)(p + 0xA) - *(s16*)(p + 0x16);
        *(s16*)(arg0 + 0xE) += *(s16*)(p + 0xE) - *(s16*)(p + 0x1A);
    }
}
