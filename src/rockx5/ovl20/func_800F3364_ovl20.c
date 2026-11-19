#include "types.h"

void func_800F3364_ovl20(u8* arg0) {
    *(s16*)(arg0 + 0x38) += 4;
    if (*(s16*)(arg0 + 0x38) >= *(s16*)(arg0 + 0x3C)) {
        *(u16*)(arg0 + 0x38) = *(u16*)(arg0 + 0x3C);
        arg0[6]++;
    }
}
