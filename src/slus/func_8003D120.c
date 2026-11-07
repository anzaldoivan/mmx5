#include "types.h"

extern void func_8002DED4(u8* obj);

void func_8003D120(u8* obj) {
    u16 f;

    if (*(s8*)(obj + 0xD3) != 0) {
        *(s32*)(obj + 0x20) = 0;
        func_8002DED4(obj);
        return;
    }
    f = *(u16*)(obj + 0x7C);
    if ((f & 3) == 0) {
        *(s32*)(obj + 0x20) = 0;
    } else if (f & 1) {
        obj[0x15] = 0x40;
        if (obj[0x89] & 1) {
            *(s32*)(obj + 0x20) = 0;
        } else if (*(s8*)(obj + 0x84) != 0) {
            *(s32*)(obj + 0x20) = *(s32*)(obj + 0x118);
        } else {
            *(s32*)(obj + 0x20) = *(s32*)(obj + 0x104);
        }
    } else {
        obj[0x15] = 0;
        if (!(obj[0x89] & 2)) {
            *(s32*)(obj + 0x20) =
                -(*(s8*)(obj + 0x84) != 0 ? *(s32*)(obj + 0x118)
                                          : *(s32*)(obj + 0x104));
        } else {
            *(s32*)(obj + 0x20) = 0;
        }
    }
    func_8002DED4(obj);
}
