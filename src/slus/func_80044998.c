#include "types.h"

extern void func_8002DED4(u8* obj);

s32 func_80044998(u8* obj) {
    s32 mask;
    s32 lim;
    s32 over;

    mask = 2;
    if (obj[0x15] != 0) {
        mask = 1;
    }
    if (obj[0x89] & mask) {
        return 1;
    }
    func_8002DED4(obj);
    if (obj[0x15] != 0) {
        over = *(s32*)(obj + 0x20);
        lim = *(s32*)(obj + 0x118);
        over = over < lim;
    } else {
        lim = *(s32*)(obj + 0x118);
        lim = -lim;
        over = lim < *(s32*)(obj + 0x20);
    }
    if (over) {
        *(s32*)(obj + 0x20) = lim;
    }
    return (s8)--obj[0x85] == 0;
}
