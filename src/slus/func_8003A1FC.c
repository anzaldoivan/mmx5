#include "types.h"

extern void func_8003C5D8(u8* obj);

void func_8003A1FC(u8* obj) {
    u32 lim;
    s32 t;

    if (*(s8*)(obj + 0x14B) < 0) {
        if (*(s8*)(obj + 2) == 0 && *(u32*)(obj + 0x14C) % 60 == 0) {
            t = obj[0x5C] - 2;
            obj[0x5C] = t;
            if ((t << 24) <= 0) {
                *(s8*)(obj + 0x5C) = -0x80;
            }
        }
        lim = 300;
        *(u32*)(obj + 0x14C) += 1;
        if (*(s8*)(obj + 2) == 0) {
            lim = 298;
        }
        if (lim < *(u32*)(obj + 0x14C)) {
            obj[0xFB] = 0;
            obj[0x14B] = 0;
            obj[0x154] = 0;
            if (*(s8*)(obj + 2) != 0) {
                obj[0x7A] = 0;
            }
            func_8003C5D8(obj);
        }
    }
}
