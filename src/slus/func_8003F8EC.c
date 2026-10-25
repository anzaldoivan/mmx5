#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_80016D54(s32, s32);
extern s32 func_80016490(s32, s32, void*);

void func_8003F8EC(u8* arg0) {
    func_8003B33C(arg0, 0x5F);
    func_80016D54(0xFF, 0);
    func_80016490(1, 0x13, arg0);
    arg0[0x67] = 1;
    arg0[0x5] = 0x26;
    arg0[0x6] = 0;
}
