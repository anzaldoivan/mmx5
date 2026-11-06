#include "types.h"

extern s32 func_80016490(s32, s32, u8*);
extern void func_8003B33C(u8*, s32);
extern void func_8003CF74(u8*, s32);
extern void func_80043E30(u8*);

s32 func_80044138(u8* obj) {
    if (!(obj[0xC9] & 8)) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x7C) & 8)) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x80) & 0x10)) {
        return 0;
    }
    if (*(s8*)(obj + 0x8E) != 0) {
        return 0;
    }
    obj[0x156] = 1;
    obj[0x8E] = 1;
    obj[0xCB] = 0;
    obj[0x8C] = 0;
    func_8003B33C(obj, 0x62);
    func_8003CF74(obj, 5);
    func_80016490(1, 0x12, obj);
    if (*(u16*)(obj + 0x7C) & 2) {
        obj[0x15] = 0;
    }
    if (*(u16*)(obj + 0x7C) & 1) {
        obj[0x15] = 0x40;
    }
    obj[5] = 0x38;
    obj[6] = 0;
    func_80043E30(obj);
    return 1;
}
