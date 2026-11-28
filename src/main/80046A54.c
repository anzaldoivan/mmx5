#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80046A54(u8* a0) {
    *(s32*)(a0 + 0x50) = 0;
    a0[3] = 0;
    a0[4]++;
}

#include "shared/func_80046A6C.c"
