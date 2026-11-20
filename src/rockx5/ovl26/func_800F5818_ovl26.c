#include "types.h"
#include "mmx5/globals.h"

void func_800F5818_ovl26(u8* obj) {
    s32 x;
    s32 v;
    u8 n;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        if (*(s16*)(obj + 0xA) < 0x990) {
            x = *(s32*)(obj + 8);
            v = 0x40;
            obj[0x15] = v;
            v = 0x9100000 - x;
            v = ((((0x9100000 - x) < 0) ? (x - 0x9100000) : (0x9100000 - x)) +
                 1) /
                108;
            *(s32*)(obj + 0x20) = -v;
        } else {
            x = *(s32*)(obj + 8);
            obj[0x15] = 0;
            v = ((((0xA100000 - x) < 0) ? (x - 0xA100000) : (0xA100000 - x)) +
                 1) /
                108;
            *(s32*)(obj + 0x20) = v;
        }
        do {
            *(s32*)(obj + 0x24) = 0x2C000;
            n = obj[6];
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x2C) = 0xD00;
        } while (0); // !FAKE: keeps the obj[6] load above the stores
        obj[6] = n + 1;
    }
}
