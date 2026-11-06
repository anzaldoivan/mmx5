#include "types.h"

extern void func_8003B33C(u8*, s32);
extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern void* func_8003D4C0(s32, s32, s32, s32);
extern void func_8003F294(u8* arg0, s32 arg1);

s32 func_8003F154(u8* obj) {
    s32 s;

    if (!((u32)(obj[0xFA] - 1) < 2 || obj[0xFA] == 4)) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x80) & 0x80)) {
        return 0;
    }
    s = obj[0xFA];
    obj[0x86] = 4;
    *(s32*)(obj + 0x20) = 0;
    obj[0xE8] = 0xB4;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x84] = 0;
    obj[0x8C] = 0;
    obj[0xE9] = 0;
    if (s == 1 || s == 4) {
        func_8003F294(obj, 0x15);
        obj[5] = 0x21;
    } else {
        func_8003B33C(obj, 0xA9);
        obj[5] = 0x23;
        func_8003D3A8(1, 0x17, 0, obj);
        func_8003D4C0(1, 0x12, 0, 0);
        obj[0x7A] = 2;
    }
    obj[6] = 0;
    return 1;
}
