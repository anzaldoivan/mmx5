#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800FD2B4_ovl39(u8* obj) {
    u8* p;
    u8 f;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0x28;
            p[2] = 0;
            *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            f = obj[0x15];
            p[0x15] = f;
            if (f == 0) {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x10;
            } else {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0x10;
            }
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) - 0x28;
            *(u8**)(p + 0x7C) = obj;
        }
        set_animation(obj, 8);
        obj[6]++;
    }
}
