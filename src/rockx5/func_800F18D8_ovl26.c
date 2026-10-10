#include "types.h"

#define D_1F80004C (*(u8**)0x1F80004C)

extern u8 D_8009A197;
extern void (*D_800F95CC_ovl26[])(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern void func_800171E8(u8*, s32);
extern s32 func_80031DD0(u8* a0);

void func_800F18D8_ovl26(u8* obj) {
    if (func_8002D938(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        obj[4] = 3;
        return;
    }
    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_800F95CC_ovl26[(signed char)obj[5]](obj);
        func_80017248(obj);
    }
    if (func_800317B8(obj) != 0) {
        obj[4] = 2;
    }
    if (D_1F80004C[0x85] != 0) {
        if (func_80031DD0(obj) < 0) {
            func_800171E8(obj, 2);
            obj[4] = 4;
        }
    }
}
