#include "types.h"
#include "mmx5/globals.h"

void func_800F0044_ovl04(u8* arg0) {
    if (D_8009A0AA >= 0x12EE) {
        ((s32(*)())func_8003D29C)(0x14, 0x40);
        arg0[6]++;
    }
}
