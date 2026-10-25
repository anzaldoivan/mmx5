#include "types.h"

extern void func_8003F294(u8* arg0, s32 arg1);
extern void func_80016D54(s32, s32);

void func_8003AB50(u8* arg0) {
    func_8003F294(arg0, 0x11);
    func_80016D54(1, 5);
    if (arg0[0x15] != 0) {
        *(s32*)(arg0 + 0x20) = *(s32*)(arg0 + 0x118);
    } else {
        *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x118);
    }
    *(s8*)(arg0 + 0x8C) = -1;
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    arg0[6] = 2;
    *(s32*)(arg0 + 0x28) = *(s32*)(arg0 + 0x11C);
}
