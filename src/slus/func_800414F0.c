#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern void func_8003CE30(u8*);

s32 func_800414F0(u8* obj) {
    u16 flags;
    s32 v;

    if (*(s8*)(obj + 0x8E) != 0) {
        return 0;
    }
    if (!(obj[0xC9] & 4)) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x7C) & 0x10F)) {
        return 0;
    }
    func_8003B33C(obj, 0x12);
    func_80016490(1, 0xF, obj);
    flags = *(u16*)(obj + 0x7C);
    *(s32*)(obj + 0x28) = *(s32*)(obj + 0x11C);
    if (flags & 4) {
        *(s32*)(obj + 0x24) = *(s32*)(obj + 0x118) / 4;
    } else if (flags & 8) {
        *(s32*)(obj + 0x24) = -(*(s32*)(obj + 0x118) / 4);
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    *(s32*)(obj + 0x2C) = 0;
    *(s8*)(obj + 0x84) = -1;
    obj[0x85] = 0x12;
    obj[0x86] = 3;
    func_8003CE30(obj);
    v = 0x37;
    obj[5] = v;
    obj[6] = 0;
    v = *(s8*)(obj + 0x14B);
    if (v == -1) {
        obj[0x7A] = 1;
    } else {
        obj[0x7A] = 2;
    }
    obj[0x156] = 1;
    return 1;
}
