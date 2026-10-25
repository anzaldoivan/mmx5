#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F7764_ovl01(u8* obj) {
    func_800171E8(obj, 7);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x8C) = 0x32;
    obj[6]++;
}
