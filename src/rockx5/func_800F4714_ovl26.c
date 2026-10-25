#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002C938();

void func_800F4714_ovl26(u8* obj) {
    u8* child;

    func_80017248(obj);
    child = func_8002C938();
    if (child != 0) {
        child[0] = 0x41;
        child[1] = 0x3A;
        child[2] = 1;
        *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
        *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
        *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
        *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
        child[0x5C] = obj[0x5C];
        *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
        child[0x15] = obj[0x15];
        *(u8**)(child + 0x80) = obj;
    }
    obj[6]++;
}
