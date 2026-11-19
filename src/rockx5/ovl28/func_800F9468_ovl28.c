#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9468_ovl28(u8* obj) {
    if (((s8*)obj)[2] == 0) {
        set_animation(obj, 3);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        *(s16*)(obj + 0x7C) = 0;
        obj[6] = 1;
    } else {
        set_animation(obj, 3);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[7] = 0;
        obj[6] = 4;
    }
}
