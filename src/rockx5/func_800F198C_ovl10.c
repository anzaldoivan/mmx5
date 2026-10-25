#include "types.h"

extern u8 D_80074EE0[];

void func_800F198C_ovl10(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 1) {
        *(u8**)(arg0 + 0x58) = D_80074EE0;
        arg0[5] = 2;
        arg0[6] = 0;
    }
}
