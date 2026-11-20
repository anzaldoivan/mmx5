#include "types.h"

extern s8 D_8009A0A5;
extern s16 D_8009A21E;

void func_800EFAD8_ovl01(u8* arg0) {
    if (D_8009A0A5 == 0x14) {
        D_8009A21E = 0x2200;
        arg0[5]++;
    }
}
