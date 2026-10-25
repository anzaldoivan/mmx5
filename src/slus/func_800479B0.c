#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800479B0(u8* obj) {
    func_800171E8(obj, 2);
    obj[0x67] = 1;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0xFFFB0000;
    obj[0x5] = 2;
}
