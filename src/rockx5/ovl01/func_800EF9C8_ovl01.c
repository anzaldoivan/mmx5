#include "types.h"
#include "mmx5/globals.h"

void func_800EF9C8_ovl01(u8* arg0) {
    u8* p = g_Player;

    *(s16*)(p + 0xE) = 0x100;
    *(s16*)(p + 0xA) = 0x2080;
    if (--arg0[0x19] == 0) {
        *(s32*)(p + 0x20) = 0x40000;
        *(s32*)(p + 0x28) = 0;
        *(s32*)(p + 0x24) = 0x4200;
        *(s32*)(p + 0x2C) = 0x699;
        arg0[5]++;
    }
}
