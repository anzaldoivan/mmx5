#include "types.h"

extern void func_8003B33C(u8*, s32);
extern u8* func_8003D3A8(s32, s32, s32, u8*);

void func_8003FAD0(u8* arg0) {
    func_8003B33C(arg0, 0x60);
    arg0[0x67] = 1;
    arg0[0x5] = 0x27;
    arg0[0x6] = 0;
    func_8003D3A8(1, 0xD, 0, 0);
    func_8003D3A8(1, 0xD, 0x40, 0);
    arg0[0x98] += 2;
    arg0[0x99] += 2;
}
