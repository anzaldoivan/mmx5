#include "types.h"

extern s16 func_8001FF18(void*, s32);
extern u8 D_80070F8C[];
extern u8 D_8009A427;

void func_800F364C_ovl24(u8* arg0) {
    *(s16*)(arg0 + 8) = func_8001FF18(D_80070F8C, 1);
    D_8009A427 = 0;
    arg0[2]++;
}
