#include "types.h"

extern void func_8002DF54(u8* a0);

void func_800F761C_ovl01(u8* a0) {
    s8 s = ((s8*)a0)[7];

    if (s == 0) {
        *(s32*)(a0 + 0x20) = 0xFFFC0000;
        a0[7]++;
        func_8002DF54(a0);
    } else if (s == 1) {
        func_8002DF54(a0);
    }
}
