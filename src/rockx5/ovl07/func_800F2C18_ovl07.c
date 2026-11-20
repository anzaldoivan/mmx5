#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

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
