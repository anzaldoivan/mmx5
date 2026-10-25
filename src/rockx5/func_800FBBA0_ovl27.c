#include "types.h"

extern void func_80016D54(s32, s32);

void func_800FBBA0_ovl27(u8* arg0) {
    if (((s8*)arg0)[2] == 0) {
        func_80016D54(2, 0x68);
    }
    arg0[5] = 1;
    arg0[6] = 0;
}
