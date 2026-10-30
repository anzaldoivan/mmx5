#include "types.h"

s32 Ovl_Load3();

void func_800F6B64_ovl18(u8* arg0) {
    if (Ovl_Load3() != 0) {
        arg0[4]++;
    }
}
