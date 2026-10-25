#include "types.h"

extern void func_8003F294(u8* arg0, s32 arg1);
extern void func_8002DF54(u8* a0);

void func_8003A82C(u8* arg0) {
    func_8003F294(arg0, 8);
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    func_8002DF54(arg0);
    arg0[5] = 4;
    arg0[6] = 0;
}
