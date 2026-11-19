#include "types.h"

extern void* D_80101544_ovl04[];
extern u8 D_80101540_ovl04[];

void func_800F19D8_ovl04(u8* a0) {
    ((void (*)(u8*))D_80101544_ovl04[((s8*)a0)[6]])(a0);
    a0[0x81] &= 3;
    a0[6] = D_80101540_ovl04[a0[0x81]];
}
