#include "types.h"

extern void func_8002DED4(u8* obj);

s32 func_800398E8(u8* obj) {
    s32 mask;
    s32 lim;
    u16 t;

    mask = 2;
    if (obj[0x15] != 0) {
        mask = 1;
    }
    if (obj[0x89] & mask) {
        return 1;
    }
    func_8002DED4(obj);
    if (obj[0x15] != 0) {
        if (*(s32*)(obj + 0x20) < *(s32*)(obj + 0x118)) {
            *(s32*)(obj + 0x20) = *(s32*)(obj + 0x118);
        }
    } else {
        lim = -*(s32*)(obj + 0x118);
        if (lim < *(s32*)(obj + 0x20)) {
            *(s32*)(obj + 0x20) = lim;
        }
    }
    obj[0x85]--;
    if (((s8*)obj)[0x85] == 0) {
        return 1;
    }
    t = *(u16*)(obj + 0x7C) & 0x103;
    if (t == 0) {
        return 1;
    }
    if (obj[0x15] != 0) {
        if (t & 2) {
            return 1;
        }
    } else if (t & 1) {
        return 1;
    }
    return 0;
}
