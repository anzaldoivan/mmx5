#include "types.h"

void func_800443E4(u8* a0, s8 a1);

void func_800443A8(u8* a0, s8 a1) {
    if (((s8*)a0)[0x45] & 0x80) {
        a0[0x45] = a0[0x45] & 0x7F;
        func_800443E4(a0, a1);
    }
}
