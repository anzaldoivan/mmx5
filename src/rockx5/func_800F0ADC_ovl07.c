#include "types.h"

extern u8 D_8009A0A0[];

void func_800F0ADC_ovl07(u8* arg0) {
    u8* p = D_8009A0A0;

    if (*(s8*)(p + 0xD5) != 0 && *(s8*)(arg0 + 0x9B) != 0) {
        *(s32*)(p + 0x8) = *(s32*)(arg0 + 0x8);
        *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
    }
}
