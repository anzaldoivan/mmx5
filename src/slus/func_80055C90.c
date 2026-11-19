#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_80055C90(u8* obj) {
    u8* g = g_Player;

    *(s32*)(g + 8) = *(s32*)(obj + 8);
    if (g[0xF5] == 3) {
        set_animation(obj, 2);
        *(s32*)(obj + 0x7C) = 40;
        obj[5]++;
    }
}
