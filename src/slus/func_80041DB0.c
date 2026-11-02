#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8003B33C(u8*, s32);
extern void func_8003CE10(u8*);
extern void func_8003CF74(u8*, s32);
extern void func_80043F10(u8* obj);
extern D1C00 D_800D1C00;

s32 func_80041DB0(u8* obj) {
    u16 flags;

    if (*(s8*)(obj + 0x2) == 0) {
        return 0;
    }
    if (*(s8*)(obj + 0xD3) != 0) {
        return 0;
    }
    if (!(obj[0xC9] & 0x80)) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x80) & 0x10)) {
        return 0;
    }
    if (*(s8*)(obj + 0x8E) != 0) {
        return 0;
    }
    flags = *(u16*)(obj + 0x7C);
    if (flags & 2) {
        obj[0x15] = 0;
    } else if (flags & 1) {
        obj[0x15] = 0x40;
    }
    func_8003CE10(obj);
    if (*(s8*)(obj + 0x5C) < (s8)(D_800D1C00.unk47[*(s8*)(obj + 0x2)] / 3)) {
        func_8003B33C(obj, 6);
    } else {
        func_8003B33C(obj, 5);
    }
    func_80016490(1, 0x14, obj);
    func_8003CF74(obj, 9);
    obj[0x5] = 0x3B;
    obj[0x6] = 0;
    func_80043F10(obj);
    obj[0x156] = 1;
    return 1;
}
