#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80032F70(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_8003240C(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_80101F54_ovl07[];
extern u8 D_80101F58_ovl07[];

void func_800FF228_ovl07(u8* obj) {
    s8 r;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    func_80017248(obj);
    r = func_80032F70(obj);
    if (r < 0) {
        if (*(s8*)(obj + 2) == 0) {
            func_8004D4F4(4, D_80101F54_ovl07, obj);
            func_8004FD90(obj, 1, 0x10, 0x20);
        } else {
            func_8004D4F4(4, D_80101F58_ovl07, obj);
            func_8004FD90(obj, 1, 8, 0x20);
        }
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s16*)(obj + 0x7E) = 5;
        obj[3] = 0;
        obj[4] = 3;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        return;
    }
    if (r > 0) {
        *(u16*)(obj + 0x42) |= 0x8000;
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    func_8003240C(obj);
    if (func_8002D938(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
        return;
    }
    obj[4] = 2;
}
