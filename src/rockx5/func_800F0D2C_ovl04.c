#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800F0D2C_ovl04(u8* obj) {
    func_800171E8(obj, 11);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0x50000;
    obj[6]++;
}
