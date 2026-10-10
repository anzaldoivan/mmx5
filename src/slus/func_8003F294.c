#include "types.h"

extern void func_8003B33C(u8*, s32);

void func_8003F294(u8* arg0, s32 arg1) {
    if (*(signed char*)(arg0 + 2) == 0 && *(signed char*)(arg0 + 0x8E) != 0) {
        arg1 += 0x70;
    }
    func_8003B33C(arg0, arg1);
}
