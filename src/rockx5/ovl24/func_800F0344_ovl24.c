#include "types.h"
#include "mmx5/globals.h"
#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

extern u16 D_800C9320;

void func_800F0344_ovl24(u8* arg0) {
    if (D_800C9320 & 0x8FF) {
        D_800D1C28_as_u8 = 0x7F;
        arg0[1] = 3;
        arg0[2] = 0;
    }
}
