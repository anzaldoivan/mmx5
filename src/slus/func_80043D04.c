#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern void func_8003CF74(u8*, s32);
extern void func_8003D120(u8*);

s32 func_80043D04(u8* arg0) {
    if (!(arg0[0xC9] & 1)) {
        return 0;
    }
    if (!(*(u16*)(arg0 + 0x80) & 0x80)) {
        return 0;
    }
    func_8003B33C(arg0, 0x5F);
    func_80016490(1, 1, arg0);
    func_8003CF74(arg0, 7);
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    arg0[0x84] = 0;
    arg0[0x86] = 6;
    arg0[0x8C] = 0;
    *(s32*)(arg0 + 0x24) = *(s32*)(arg0 + 0x108);
    *(s32*)(arg0 + 0x2C) = *(s32*)(arg0 + 0x110);
    func_8003D120(arg0);
    arg0[5] = 6;
    arg0[6] = 0;
    return 1;
}
