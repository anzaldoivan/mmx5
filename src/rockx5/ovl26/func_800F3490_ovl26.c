#include "types.h"
#include "mmx5/globals.h"

void func_800F3490_ovl26(u8* obj) {
    u8* p;
    s32 n;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        p = g_Player;
        if (*(s16*)(obj + 0xA) < *(s16*)(p + 0xA)) {
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) =
                ((*(s32*)(p + 8) - *(s32*)(obj + 8)) >= 0
                     ? (*(s32*)(p + 8) - *(s32*)(obj + 8)) + 0x10000
                     : (*(s32*)(obj + 8) - *(s32*)(p + 8)) + 0x10000) /
                108;
        } else {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) =
                -(((*(s32*)(p + 8) - *(s32*)(obj + 8)) >= 0
                       ? (*(s32*)(p + 8) - *(s32*)(obj + 8)) + 0x10000
                       : (*(s32*)(obj + 8) - *(s32*)(p + 8)) + 0x10000) /
                  108);
        }
        n = obj[6] + 1;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x2D000;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[6] = n;
    }
}
