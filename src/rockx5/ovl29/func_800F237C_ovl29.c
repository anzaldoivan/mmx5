#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_8002E024(void*, void*);
extern void set_velocity_from_angle(void*, s32);

void func_800F237C_ovl29(u8* obj) {
    s8 kind;
    u8* p;

    kind = *(s8*)(obj + 0x45);
    if (kind == 2) {
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = kind;
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            p[2] = obj[2] & 1;
            p[0x15] = obj[0x15];
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            set_velocity_from_angle(obj, func_8002E024(obj, g_Player));
            if ((obj[0x15] == 0 && *(s32*)(obj + 0x20) < 0) ||
                (obj[0x15] != 0 && *(s32*)(obj + 0x20) > 0)) {
                *(s32*)(p + 0x20) = *(s32*)(obj + 0x20);
                *(s32*)(p + 0x24) = *(s32*)(obj + 0x24);
            } else {
                *(s32*)(p + 0x20) = *(s32*)(obj + 0x88);
                *(s32*)(p + 0x24) = *(s32*)(obj + 0x8C);
            }
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0;
        }
    }
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 1);
        obj[5] = 3;
        obj[6] = 0;
    }
    animate_object(obj);
}
