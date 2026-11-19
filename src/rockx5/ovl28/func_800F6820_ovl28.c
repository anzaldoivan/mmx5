#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern s32 D_8009A0A8;

void func_800F6820_ovl28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 7) == 2) {
        set_animation(obj, 4);
        D_1F80004C.bytes[0x8C] = 0;
        animate_object(obj);
        obj[0x67] = 1;
        if (D_8009A0A8 > *(s32*)(obj + 8)) {
            *(s32*)(obj + 0x20) = -0x20000;
            obj[0x15] = 0;
        } else {
            *(s32*)(obj + 0x20) = 0x20000;
            obj[0x15] = 0x40;
        }
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x5D000;
        *(s32*)(obj + 0x2C) = 0x4200;
        obj[6]++;
    }
}
