#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F4BA0_ovl10(u8* a0) {
    g_Player[0xCA] = 0;
    func_8003D29C(0x14, g_Player[0x15]);
    a0[5] = 1;
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    set_animation(a0, 0x14);
    *(s16*)(a0 + 0x7C) = 0x7F;
    *(s16*)(a0 + 0x7E) = 0x19;
    a0[0x61] = 0x19;
    if (*(signed char*)(a0 + 2) == 0) {
        func_8002D9EC(a0, 0x60, 0x60);
    } else {
        a0[3] = 0;
    }
}
