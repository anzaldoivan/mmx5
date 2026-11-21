#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F2B2C_ovl07(u8* obj) {
    if (((s8*)obj)[2] != 0) {
        set_animation(obj, 0xB);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0xFFFC0000;
        *(u16*)(obj + 0x8A) = *(u16*)(obj + 0xE);
    } else {
        set_animation(obj, 0xC);
        if (obj[0x86] != 0) {
            *(s32*)(obj + 0x20) = 0xFFFC0000;
        } else {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = 0x40000;
        }
        *(s32*)(obj + 0x24) = 0;
        *(u16*)(obj + 0x8A) = *(u16*)(obj + 0xA);
    }
    play_sound(0, 0x11, obj);
    obj[0x83] = 0;
    obj[0x84] = 0;
    obj[6]++;
}

void func_800F2BD4_ovl07(u8* p) {
    u16 t;

    if (p[0x87] == 0) {
        t = *(u16*)(p + 0x88);
        if (t < 60) {
            p[6]++;
            return;
        }
        *(u16*)(p + 0x88) = t - 1;
    }
}

void func_800F2C18_ovl07(u8* o) {
    u16 t;

    move_object(o);
    animate_object(o);
    if (((s8*)o)[2] != 0) {
        *(s32*)(o + 0x24) = -*(s32*)(o + 0x24);
    } else {
        *(s32*)(o + 0x20) = -*(s32*)(o + 0x20);
    }
    t = *(u16*)(o + 0x88);
    if (t == 0) {
        if (((s8*)o)[2] != 0) {
            *(s32*)(o + 0x24) = -0x80000;
            *(s32*)(o + 0x20) = 0;
            o[0x47] = 0x5E;
            *(u16*)(o + 0xE) = *(u16*)(o + 0x8A);
        } else {
            if (o[0x86] != 0) {
                *(s32*)(o + 0x20) = -0x80000;
            } else {
                *(s32*)(o + 0x20) = 0x80000;
            }
            *(s32*)(o + 0x24) = 0;
            o[0x47] = 0x10;
            *(u16*)(o + 0xA) = *(u16*)(o + 0x8A);
        }
        o[6]++;
        return;
    }
    *(u16*)(o + 0x88) = t - 1;
}
