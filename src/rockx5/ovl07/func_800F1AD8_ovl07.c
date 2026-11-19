#include "types.h"

extern s16 D_8009A202;
extern u16 D_80100E94_ovl07[][2];

void func_800F1AD8_ovl07(u8* arg0) {
    if (D_8009A202 >= (s16)D_80100E94_ovl07[((s8*)arg0)[2]][0]) {
        arg0[4]++;
    }
}
