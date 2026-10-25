#include "types.h"

extern void func_8003B33C(u8*, s32);

void func_8003AC44(u8* obj) {
    func_8003B33C(obj, 0x13);
    *(s8*)(obj + 0x67) = -1;
    *(s8*)(obj + 0x8C) = -1;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    obj[0x84] = 0;
    obj[6] = 2;
    *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
}
