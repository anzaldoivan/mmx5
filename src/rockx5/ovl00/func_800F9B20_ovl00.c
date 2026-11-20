#include "types.h"

extern u8 D_8009A1F8[];

void func_800F9B20_ovl00(u8* arg0) {
    u8* p = D_8009A1F8;

    *(s16*)(p + 0x5E) = 0x1580 - *(u16*)(arg0 + 0xA);
    *(s16*)(p + 0x62) = 0x280 - *(u16*)(arg0 + 0xE);
}
