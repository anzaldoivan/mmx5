#include "types.h"

extern s32 func_800317B8(u8* a0);

void func_800F2E40_ovl10(u8* a0) {
    u8* p = *(u8**)(a0 + 0x7C);

    if (((s8*)p)[0x45] == 2) {
        a0[4] = 3;
        return;
    }
    a0[0x8C] = -p[0x45];
    a0[0x8E] = p[0x45];
    a0[0x62] = 0;
    func_800317B8(a0);
}
