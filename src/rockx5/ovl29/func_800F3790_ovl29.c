#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F3790_ovl29(u8* obj) {
    u8* p;
    s32 v;

    if (D_8009A0AA > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    set_animation(obj, 3);
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x26;
        p[2] = 2;
        *(u8**)(p + 0x50) = obj;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x26;
        p[2] = 3;
        *(u8**)(p + 0x50) = obj;
    }
    obj[0x67] = 1;
    play_sound(2, 0xAC, obj);
    v = 0xFFFF4000;
    obj[6]++;
    if (obj[0x15] != 0) {
        v = 0xC000;
    }
    *(s32*)(obj + 0x20) = v;
    *(s32*)(obj + 0x24) = 0x38000;
    *(s32*)(obj + 0x28) = 0x800;
    *(s32*)(obj + 0x2C) = -0x800;
    *(u16*)(obj + 0x88) = *(u16*)(obj + 0xE);
}
