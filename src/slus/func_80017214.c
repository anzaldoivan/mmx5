#include "types.h"

void func_80017214(u8* arg0, s32 arg1, s32 arg2) {
    s32* p;

    p = (*(s32***)(arg0 + 0x30))[arg1];
    arg0[0x48] = 0xFF;
    arg0[0x17] = arg1;
    p += arg2;
    *(s32**)(arg0 + 0x34) = p;
    *(s32*)(arg0 + 0x44) = *p;
}
