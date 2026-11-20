#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_8003D010(s8 dmg);

void func_800F2A9C_ovl04(u8* obj) {
    u8* src = g_Player;

    *(u16*)(obj + 0xA) = *(u16*)(src + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(src + 0xE);
    if (--*(s16*)(obj + 0x7C) == -1) {
        set_animation(obj, 4);
        func_8003D010(2);
        *(s16*)(obj + 0x7C) = 0x78;
    }
}
