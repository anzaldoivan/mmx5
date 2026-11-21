#include "types.h"
#include "addr.h"

void func_800FBF74_ovl07(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    D_1F80004C.bytes[0x92] = 0;
    func_800FB030_ovl07(obj);
}
