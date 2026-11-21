#include "types.h"
#include "mmx5/globals.h"

void func_800F20C4_ovl20(u8* arg0) {
    *(s16*)(arg0 + 0xA) += 8;
    if (*(s16*)(arg0 + 0xA) >= 0x190) {
        *(s16*)(arg0 + 0xA) = 0x190;
        arg0[5]++;
        D_800D1C28[1] = 0;
    }
}

extern s16 D_8009A256;

void func_800F2108_ovl20(u8* arg0) {
    s16 t = D_8009A256;

    if ((s16)(t % 320) == 0 && t != 320) {
        arg0[4] = 3;
        return;
    }
    if (D_800D1C28[1] != 0) {
        arg0[5]++;
    }
}

void func_800F2190_ovl20(u8* arg0) {
    *(s16*)(arg0 + 0xA) -= 8;
    if (*(s16*)(arg0 + 0xA) < 0xC1) {
        *(s16*)(arg0 + 0xA) = 0xC0;
        D_800D1C28[1] = 0;
        arg0[4] = 3;
    }
}
