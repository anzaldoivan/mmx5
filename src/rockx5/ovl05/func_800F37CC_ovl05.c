#include "types.h"
#include "mmx5/globals.h"

extern s32 func_8003240C(u8*);

void func_800F37CC_ovl05(u8* a0) {
    s32 r;

    func_8002D89C(a0);
    func_8003240C(a0);
    r = func_80031DD0(a0);
    if (r < 0) {
        a0[4]++;
        *(s32*)(a0 + 0x7C) = 0;
        func_8004FD90(a0, 1, 0x1F, 0x3F);
        func_8004FD90(a0, 1, 0x1F, 0x3F);
        func_8004FD90(a0, 1, 0x1F, 0x3F);
        func_8004FD90(a0, 1, 0x1F, 0x3F);
        *(u16*)(a0 + 0x42) &= 0x7FFF;
    } else if (r > 0) {
        *(u16*)(a0 + 0x42) |= 0x8000;
    } else {
        *(u16*)(a0 + 0x42) &= 0x7FFF;
    }
}
