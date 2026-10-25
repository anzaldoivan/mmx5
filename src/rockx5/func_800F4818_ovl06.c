#include "types.h"

extern u32 func_8002DFB0(void);

void func_800F4818_ovl06(u8* a0) {
    u32 r = func_8002DFB0();
    *(s16*)(a0 + 0x7E) = 1;
    a0[6]++;
    *(s16*)(a0 + 0x7C) = (u8)(r % 50) + 40;
}
