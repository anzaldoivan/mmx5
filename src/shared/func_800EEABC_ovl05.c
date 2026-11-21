#include "types.h"

extern u8 D_800F4828_ovl05[][14];

void func_800EEABC_ovl05(u8* arg0) {
    arg0[0x14] = 0;
    *(u8**)(arg0 + 0x18) = D_800F4828_ovl05[((s8*)arg0)[2]];
    arg0[4]++;
}
