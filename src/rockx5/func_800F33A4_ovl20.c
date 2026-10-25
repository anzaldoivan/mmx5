#include "types.h"

extern s8 D_800D1C28[];

void func_800F33A4_ovl20(u8* arg0) {
    s32 v;

    v = *(u16*)(arg0 + 0x3A) + 3;
    *(s16*)(arg0 + 0x3A) = v;
    if ((s16)v >= *(s16*)(arg0 + 0x3E)) {
        *(s16*)(arg0 + 0x3A) = *(s16*)(arg0 + 0x3E);
        arg0[6]++;
        if (((s8*)arg0)[2] == 0) {
            D_800D1C28[1] = 0;
        }
    }
}
