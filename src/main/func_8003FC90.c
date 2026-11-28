#include "types.h"

void func_8003FC90(u8* obj, s32 arg1) {
    *(u8*)(obj + 0x67) = 1;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(u8*)(obj + 0x5) = 0x2A;
    *(u8*)(obj + 0x6) = arg1;
    *(u8*)(obj + 0x7) = 0;
    *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
}
