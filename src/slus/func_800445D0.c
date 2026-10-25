#include "types.h"

extern void func_800443A8(u8*, s8);

void func_800445D0(u8* a0) {
    u8 t;

    func_800443A8(a0, 0x24);
    t = a0[0x45];
    if (t & 0x20) {
        a0[0x45] = t & 0x1F;
        if (a0[0x15] != 0) {
            *(s32*)(a0 + 0x20) = 0x40000;
        } else {
            *(s32*)(a0 + 0x20) = 0xFFFC0000;
        }
        *(s32*)(a0 + 0x28) = -0x4000;
        *(s32*)(a0 + 0x24) = 0x6C000;
        *(s32*)(a0 + 0x2C) = *(s32*)(a0 + 0x110);
        if (*(s8*)(a0 + 0xD3) == 0 && *(s8*)(a0 + 0x14B) != -1) {
            a0[0x7A] = 0;
        }
        a0[6]++;
    }
}
