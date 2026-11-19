#include "types.h"

extern u8 D_8009A1F8[];

void func_800FA8B8_ovl53(u8* s) {
    u8* p;

    if (++*(s16*)(s + 4) >= 10) {
        p = D_8009A1F8;
        *(s16*)(p + 0x5E) = 0x1C0;
        *(s16*)(p + 0x62) = 0x100;
        p[0x57] = 1;
        p[0xA0] = 1;
        *(s16*)(s + 4) = 0;
        s[1]++;
    }
}
