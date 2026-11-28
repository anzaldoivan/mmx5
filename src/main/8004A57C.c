#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_8004A57C(u8* arg0) {
    move_object(arg0);
    if (++*(s16*)(arg0 + 0x8C) >= 11) {
        *(s16*)(arg0 + 0x8C) = 0;
        arg0[5]++;
    }
}

void func_8004A5D4(u8* arg0) {
    *(s16*)(arg0 + 0x8C) += 1;
    if (*(s16*)(arg0 + 0x8C) >= 40) {
        arg0[5]++;
    }
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_8004A610(u8* obj) {
    u8* p = g_Player;
    s32 dx;
    s32 dz;
    s32 a;
    s32 s;
    s32 t;
    s32 c;
    s32 u;

    dx = *(s16*)(p + 0xA) - *(s16*)(obj + 0xA);
    dz = *(s16*)(p + 0xE) - *(s16*)(obj + 0xE);
    if (dx * dx + dz * dz < 0x25) {
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x68) = 0;
        set_animation(obj, 1);
        *(s16*)(obj + 0xA) = *(s16*)(p + 0xA);
        *(s16*)(obj + 0xE) = *(s16*)(p + 0xE);
        obj[5]++;
        return;
    }
    a = ratan2(dz, dx);
    *(s32*)(obj + 0x20) = rcos(a);
    s = -rsin(a);
    t = s << 4;
    *(s32*)(obj + 0x24) = ((s << 5) + t) << 1;
    c = *(s32*)(obj + 0x20);
    u = c << 4;
    *(s32*)(obj + 0x20) = ((c << 5) + u) << 1;
    move_object(obj);
}

void func_8004A70C(u8* e) {
    u8* p = g_Player;

    *(s16*)(e + 0xA) = *(s16*)(p + 0xA);
    *(s16*)(e + 0xE) = *(s16*)(p + 0xE);
    if (*(s8*)(e + 0x46) == 0) {
        e[3] = 0;
        e[4] = 3;
    }
}
