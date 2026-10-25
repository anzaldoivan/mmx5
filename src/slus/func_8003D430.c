#include "types.h"

void* func_8002CC08(s32 p, s32 backward);
extern u8 D_8009A0B4;

void* func_8003D430(s8 arg0, s8 arg1, s8 arg2, s32 arg3) {
    u8* p;

    p = func_8002CC08(arg3, 0);
    if (p != 0) {
        p[0] = arg0;
        p[1] = arg1;
        p[2] = arg2;
        p[0x14] = D_8009A0B4;
        if (arg3 != 0) {
            *(s32*)(p + 0x7C) = arg3;
        }
        return p;
    }
    return 0;
}
