#include "types.h"

extern u8 D_800D1C32;

void func_800F0F98_ovl20(u8* arg0) {
    D_800D1C32 = 1;
    *(s16*)(arg0 + 8) = 0;
    arg0[2]++;
}
