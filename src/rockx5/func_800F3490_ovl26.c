#include "types.h"

extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];

void func_800F3490_ovl26(u8* obj) {
    u8* p;
    s32 n;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        p = D_8009A0A0;
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
