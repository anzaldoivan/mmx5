#include "types.h"

extern u8 D_8009A1F8[];

void func_800FAD9C_ovl50(u8* arg0) {
    u8* p;

    if (*(s16*)(arg0 + 6) < 90) {
        (*(s16*)(arg0 + 6))++;
        return;
    }
    p = D_8009A1F8;
    *(s32*)(p + 0xB4) += 0xCCCCC;
    (*(s16*)(arg0 + 4))++;
    if (*(s16*)(arg0 + 4) >= 20) {
        *(s32*)(p + 0xB4) = 0x3000000;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
