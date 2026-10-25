#include "types.h"

extern u16 D_800C9320;
extern u8 D_800D1C28;

void func_800F0308_ovl24(u8* arg0) {
    if (D_800C9320 & 0x8FF) {
        D_800D1C28 = 0x7F;
        arg0[2]++;
    }
}
