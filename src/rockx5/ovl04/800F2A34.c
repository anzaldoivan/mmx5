#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2A34_ovl04(u8* arg0) {
    u8* p;

    D_1F80004C.bytes[0x84] = 0;
    p = g_Player;
    *(s16*)(p + 0xA) = *(s16*)(arg0 + 0xA);
    *(s16*)(p + 0xE) = *(s16*)(arg0 + 0xE);
    p[3] = 0;
    set_animation(arg0, 3);
    *(s16*)(arg0 + 0x7C) = 0x78;
    arg0[6]++;
}

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
