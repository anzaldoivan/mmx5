#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 D_800771C8[];

void func_8004B1FC(u8* obj) {
    u8* g = g_Player;

    if (*(s8*)(g + 5) != 0x29) {
        obj[4] = 3;
        return;
    }
    if (++*(s16*)(obj + 0x8C) >= 4) {
        set_animation(obj, 0);
        *(s32**)(obj + 0x50) = D_800771C8;
        *(s32*)(obj + 0x68) = 0;
        *(u16*)(obj + 0xA) = *(u16*)(g + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(g + 0xE);
        obj[0x64] = 1;
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x10000;
            *(s32*)(obj + 0x28) = 0x1000;
        } else {
            *(s32*)(obj + 0x20) = -0x10000;
            *(s32*)(obj + 0x28) = -0x1000;
        }
        *(s32*)(obj + 0x24) = 0x8000;
        *(s32*)(obj + 0x2C) = 0x100;
        obj[3] = 1;
        *(s16*)(obj + 0x8C) = 0;
        obj[5]++;
    }
}

#define D_800EEC60_ovl00 func_8004B2E4
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
