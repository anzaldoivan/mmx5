#include "types.h"

extern void func_800171E8(u8*, s32);

void func_800F2CBC_ovl01(u8* p) {
    func_800171E8(p, 1);
    if (p[0x15] == 0x40) { // !FAKE: identical arms keep the dead lbu/li (C0225)
        *(s32*)(p + 0x28) = -0xB21;
    } else {
        *(s32*)(p + 0x28) = -0xB21;
    }
    p[6]++;
}
