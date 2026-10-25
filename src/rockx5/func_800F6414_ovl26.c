#include "types.h"

extern void func_80017248(u8* obj);

void func_800F6414_ovl26(u8* obj) {
    s32 speed;
    s8 idx;

    if (*(u8*)(*(u8**)(obj + 0x7C) + 0x96) == 0) {
        speed = 0x60000;
    } else {
        speed = -0x60000;
    }
    func_80017248(obj);
    if (*(s8*)(*(u8**)(obj + 0x7C) + 7) == 0) {
        obj[6]++;
        idx = *(s8*)(obj + 2);
        if (idx < 8) {
            *(s16*)(obj + 0x90) = (idx + 1) * 35;
            *(s32*)(obj + 0x20) = -speed;
        } else {
            *(s16*)(obj + 0x90) = (idx - 7) * 35;
            *(s32*)(obj + 0x20) = 0;
        }
    }
}
