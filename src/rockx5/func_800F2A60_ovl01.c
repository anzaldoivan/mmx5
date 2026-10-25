#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F2A60_ovl01(u8* obj) {
    s32 v;

    func_800171E8(obj, 2);
    v = -0x20000;
    if (obj[0x15] != 0) {
        v = 0x20000;
    }
    *(s32*)(obj + 0x20) = v;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
}
