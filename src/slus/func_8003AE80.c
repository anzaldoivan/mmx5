#include "types.h"

extern void func_8003F294(u8* arg0, s32 arg1);
extern void func_8003D250(u8* arg0);
extern void func_8003CE10(u8*);

void func_8003AE80(u8* arg0) {
    func_8003F294(arg0, 0xF);
    if (arg0[0xFA] != 3) {
        func_8003D250(arg0);
    }
    *(s8*)(arg0 + 0x67) = -1;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    *(s32*)(arg0 + 0x24) = *(s32*)(arg0 + 0x120);
    func_8003CE10(arg0);
    arg0[5] = 0xB;
    arg0[6] = 0;
}
