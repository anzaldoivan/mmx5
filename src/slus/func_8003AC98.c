#include "types.h"

extern void func_8003B33C(u8*, s32);

void func_8003AC98(u8* obj) {
    func_8003B33C(obj, 0x84);
    *(s8*)(obj + 0x67) = -1;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    obj[0x84] = 0;
    obj[0x8C] = 0;
    obj[5] = 7;
    obj[6] = 0;
    *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
}
