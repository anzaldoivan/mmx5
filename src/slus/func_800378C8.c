#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003A70C(u8* obj);
extern void func_8003B33C(u8*, s32);
extern void func_8003CD08(u8* obj);

void func_800378C8(u8* obj) {
    if (((s8*)obj)[0xD4] == 0) {
        func_8003CD08(obj);
        if (obj[0x89] & 8) {
            obj[0x67] = 0;
            func_8003A70C(obj);
        } else {
            func_8003B33C(obj, 0xB);
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x24) = 0;
            ((s8*)obj)[0x67] = -1;
            *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
            obj[6]++;
        }
        obj[0x84] = 0;
        obj[0x86] = 0;
    } else if (((s8*)obj)[0x67] == 0) {
        func_80017248(obj);
    }
}
