#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern u8* func_8003D3A8(s32, s32, s32, u8*);

void func_8003FB4C(u8* arg0) {
    func_8003B33C(arg0, 0x61);
    func_80016490(1, 0x10, arg0);
    arg0[0x67] = 1;
    arg0[0x5] = 0x28;
    arg0[0x6] = 0;
    func_8003D3A8(1, 0xE, 0, 0);
    arg0[0x98]++;
    arg0[0x99]++;
    arg0[0xA6]++;
}
