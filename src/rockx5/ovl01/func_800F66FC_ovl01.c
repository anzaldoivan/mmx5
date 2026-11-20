#include "types.h"
#include "addr.h"

void func_800F66FC_ovl01(u8* a0) {
    // !FAKE: register pin keeps the reloaded scratchpad pointer in v1
    register u8* p asm("$3");

    switch (D_1F80004C.bytes[0x86]) {
    case 0:
        *(s32*)(a0 + 0x24) = -0x8000;
        break;
    case 1:
        *(s32*)(a0 + 0x24) = -0x8000;
        break;
    case 2:
        *(s32*)(a0 + 0x24) = 0x8000;
        break;
    case 3:
        *(s32*)(a0 + 0x24) = 0x8000;
        break;
    }
    p = D_1F80004C.bytes;
    p[0x86] = (p[0x86] + 1) & 3;
    D_1F80004C.bytes[0x85] = 0x20;
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x28) = 0;
    *(s32*)(a0 + 0x2C) = 0;
    a0[6]++;
}
