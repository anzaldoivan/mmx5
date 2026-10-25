#include "types.h"

extern void func_8003F294(u8* arg0, s32 arg1);

void func_8003A94C(u8* arg0) {
    func_8003F294(arg0, 0xB);
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s8*)(arg0 + 0x67) = -1;
    *(s32*)(arg0 + 0x2C) = *(s32*)(arg0 + 0x110);
    if (*(s8*)(arg0 + 0x84) != 0) {
        arg0[0x84] = 0;
        *(s8*)(arg0 + 0x8C) = -1;
    }
    arg0[5] = 7;
    arg0[6] = 0;
}
