#include "types.h"

void func_80051634(u8* obj) {
    *(s32*)(obj + 0x1C) -= *(s32*)(obj + 0x3C);
    *(s32*)(obj + 0x24) -= *(s32*)(obj + 0x3C);
    *(s32*)(obj + 0x3C) += 0x8000;
    if (*(s32*)(obj + 0x1C) <= *(s32*)(obj + 0x14)) {
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0x14);
        obj[5] = 6;
        *(s32*)(obj + 0x24) = *(s32*)(obj + 0x2C);
    }
}
