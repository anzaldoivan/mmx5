#include "types.h"
#include "mmx5/globals.h"

extern void set_stand_animation_by_hp(u8* obj);

void func_80039F1C(u8* obj) {
    s16 d;
    s32 go;
    u16 t;

    go = 0;
    d = (*(u16*)(obj + 0xA) - 0x40) -
        (u16)D_8009A1F8.bg[*(s8*)(obj + 0x14)].x_pos.i.hi;
    if (d != 0) {
        if (d > 0) {
            obj[0x15] = 0;
            go = d < 3;
        } else {
            obj[0x15] = 0x40;
            if (d >= -2) {
                goto one; // !FAKE: goto kept for the matching branch layout
            }
        }
    } else {
    one: // !FAKE: goto kept for the matching branch layout
        go = 1;
    }
    if (go != 0) {
        set_stand_animation_by_hp(obj);
        t = D_8009A1F8.bg[*(s8*)(obj + 0x14)].x_pos.i.hi;
        *(s8*)(obj + 0xD0) = -1;
        obj[0x15] = 0x40;
        obj[5] = 0x14;
        *(u16*)(obj + 0xA) = t + 0x40;
    }
}
