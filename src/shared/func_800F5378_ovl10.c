#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F5378_ovl10(u8* obj) {
    s32 off;
    s32 d;
    s32 v;
    u8* p;
    u8* q;

    p = g_Player;
    if (*(s16*)(p + 0xA) < *(s16*)(obj + 0xA)) {
        obj[0x15] = 0;
        off = 0x400000;
    } else {
        obj[0x15] = 0x40;
        off = 0xFFC00000;
    }
    q = g_Player;
    d = ABS(*(s32*)(q + 8) + off - *(s32*)(obj + 8));
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x64000;
    *(s32*)(obj + 0x2C) = 0x3800;
    v = (d + 0x10000) / 60;
    *(s32*)(obj + 0x20) = v;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -v;
    }
    set_animation(obj, 2);
    obj[6] = 1;
}
#undef ABS
