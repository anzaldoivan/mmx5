#include "types.h"

s32 func_8003E6FC(void*, s8);

void func_8003F7F8(u8* arg0, s8 arg1) {
    u16* p;
    s32 v = func_8003E6FC(arg0, arg1);
    p = (u16*)(arg0 + 0xA8);
    p += ((s8*)arg0)[0x93];
    *p -= v;
}
