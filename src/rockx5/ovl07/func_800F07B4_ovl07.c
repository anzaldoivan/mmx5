#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F07B4_ovl07(u8* obj) {
    s32 v;

    if (obj[0x82] == obj[0x83]) {
        return;
    }
    if (obj[0x80] & 2) {
        return;
    }
    switch (obj[0x82]) {
    case 0:
        set_animation(obj, 2);
        v = 0x45;
        break;
    case 1:
        set_animation(obj, 1);
        v = 0x43;
        break;
    case 2:
        set_animation(obj, 0);
        v = 0x41;
        break;
    default:
        return;
    }
    g_Player[0xD8] = v;
    g_Player[6] = 0;
}
