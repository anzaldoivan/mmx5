#include "types.h"

extern void ClearOTagR(void* ot, s32 n);

void func_80012B70(u8* arg0) {
    ClearOTagR(arg0 + 0x70, 0x10);
    arg0[0x2A] = 0;
    arg0[0x2C] = 1;
    arg0[0x2D] = 0;
    arg0[0x2E] = 0;
    arg0[0x2F] = 0;
}
