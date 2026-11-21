#include "types.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

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

extern void func_800F6C48_ovl01(u8* a0);

void func_800F67B0_ovl01(u8* a0) {
    move_object(a0);
    animate_object(a0);
    if (--D_1F80004C.bytes[0x85] == 0xFF) {
        if (--D_1F80004C.bytes[0x84] == 0xFF) {
            a0[5] = 3;
            func_800F6C48_ovl01(a0);
        }
        a0[6] = 0;
    }
}
