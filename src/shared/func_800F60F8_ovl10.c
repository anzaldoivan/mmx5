#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F60F8_ovl10(u8* obj) {
    s8 state;
    u8* p;

    animate_object(obj);
    state = *(s8*)(obj + 0x45);
    if (state == 1) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x23;
            p[2] = state;
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42);
            p[0x15] = obj[0x15];
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8) + 0xFFE00000;
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
        }
        obj[6] = state;
        *(s16*)(obj + 0x7E) = 0x84;
    }
}

void func_800F61C8_ovl10(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7E) == 0) {
        obj[6] = 2;
    }
}

extern u8 D_80076060[];

void func_800F620C_ovl10(u8* obj) {
    *(u8**)(obj + 0x58) = D_80076060;
    set_animation(obj, 0);
    obj[5] = 4;
    obj[6] = 2;
}
