#include "types.h"

extern void func_800FAE20_ovl27(u8* obj, s32 angle);

void func_800FA828_ovl27(u8* obj) {
    if (--*(s16*)(obj + 0x7E) == 0) {
        func_800FAE20_ovl27(obj, 0x400);
        func_800FAE20_ovl27(obj, 0xC00);
        *(s16*)(obj + 0x7E) = 3;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 4;
        obj[6]++;
    }
}
