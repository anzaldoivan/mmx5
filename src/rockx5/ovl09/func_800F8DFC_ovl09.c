#include "types.h"

extern u8* func_8002C938();

void func_800F8DFC_ovl09(u8* arg0, s16 arg1, s16 arg2, u8 arg3, s8 arg4,
                         u8 arg5) {
    u8* p;

    p = func_8002C938();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x27;
        p[2] = arg3;
        *(s16*)(p + 0xA) = arg1;
        *(s16*)(p + 0x8) = 0;
        *(s16*)(p + 0xE) = arg2;
        *(s16*)(p + 0xC) = 0;
        p[0x5C] = arg4;
        *(s32*)(p + 0x10) = 0;
        *(u8**)(p + 0x80) = arg0;
        p[0x84] = arg5;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        if (arg3 == 1) {
            *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        } else {
            *(u16*)(p + 0x42) = 0x7CCC;
        }
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
    }
}
