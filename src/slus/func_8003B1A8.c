#include "types.h"

extern void func_800177B0(s32, s32);
extern void func_8003B28C(u8* obj);
extern void func_8003B33C(u8*, s32);
extern void func_8003CE64(u8* obj);
extern void func_8003D0A0(u8* obj);
extern void func_8003EC00(u8* obj);
extern void func_8003ED10(u8* obj);
extern u8 D_800D1C00[];

void func_8003B1A8(u8* obj) {
    u8* base;
    u8 flags;

    func_8003CE64(obj);
    func_8003EC00(obj);
    base = D_800D1C00;
    flags = base[0xF];
    base[0x1C] = 1;
    if (flags & 0x10) {
        func_8003D0A0(obj);
        func_8003ED10(obj);
        if (((s8*)obj)[2] == 0) {
            func_800177B0(0, 0x7F);
        } else {
            func_800177B0(1, 0x7F);
            obj[0x93] = 0;
        }
        obj[5] = 0x19;
        obj[6] = 0;
        return;
    }
    if (flags & 0x40) {
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
        return;
    }
    func_8003B33C(obj, 3);
    func_8003ED10(obj);
    if (((s8*)obj)[2] != 0) {
        obj[0x93] = 0;
    }
    func_8003B28C(obj);
}
