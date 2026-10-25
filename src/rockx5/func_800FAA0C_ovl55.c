#include "types.h"

extern void func_800177B0(s32, s32);
extern signed char D_8009A424;

void func_800FAA0C_ovl55(u8* arg0) {
    if (D_8009A424 == 0) {
        arg0[1]++;
        func_800177B0(0x16, 0x7F);
        *(s16*)(arg0 + 4) = 0;
    }
}
