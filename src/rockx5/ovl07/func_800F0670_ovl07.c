#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F0670_ovl07(u8* obj) {
    if (*(u16*)(obj + 0x8C) & 0x80) {
        if (obj[0x7D] == 0) {
            obj[5] = 2;
            obj[6] = 0;
            *(s32*)(obj + 0x24) = 0x68000;
            obj[0x80] |= 2;
            set_animation(obj, 2);
            {
                u8 v = 0x45;
                u8* g = g_Player;
                g[0xD8] = v;
                g[6] = 0;
            }
        } else {
            s32 b = obj[0x80];
            *(s32*)(obj + 0x24) = 0x68000;
            obj[6] = 0;
            *(u16*)(obj + 0x8E) = 1;
            obj[0x67] = 1;
            b |= 2;
            obj[0x80] = b;
        }
    }
}
