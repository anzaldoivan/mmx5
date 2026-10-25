#include "types.h"

extern u8 D_800D1F3C;
extern u8 D_8009A1F8[];

void func_800FA8C8_ovl54(u8* arg0) {
    u8* p;

    if (D_800D1F3C == 2) {
        p = D_8009A1F8;
        *(s16*)(p + 0x5E) = 0x300;
        *(s16*)(p + 0x62) = 0x100;
        p[0x57] = 1;
        p[0xA0] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
