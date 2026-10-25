#include "types.h"

extern void func_8003F2D8(u8* arg0, s32 arg1);
extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);

void func_800407CC(u8* arg0) {
    func_8003F2D8(arg0, 0x15);
    if (((s8*)arg0)[0x45] & 0x80) {
        arg0[0x45] &= 0x7F;
        func_8003D4C0(0x21, 0x21, 0, 0);
        arg0[6]++;
    }
}
