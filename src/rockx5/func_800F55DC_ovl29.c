#include "types.h"

extern void func_80017248(u8* obj);

void func_800F55DC_ovl29(u8* obj) {
    u8* child;

    func_80017248(obj);
    child = *(u8**)(obj + 0x80);
    if (*(s8*)(child + 0x46) < 0) {
        child[4] = 2;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x4200;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
    }
}
