#include "types.h"

extern s32 func_80030A0C(u8* obj);
extern void func_80040180(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_8003B0EC(u8*);

s32 func_80039D2C(u8* obj) {
    if (*(s8*)(obj + 0xD3) != 0) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x7C) & 4)) {
        return 0;
    }
    if (func_80030A0C(obj) != 0x20) {
        return 0;
    }
    if (*(s8*)(obj + 0x8E) != 0) {
        func_80040180(obj);
    } else {
        func_8003B33C(obj, 0x1F);
        func_8003B0EC(obj);
    }
    return 1;
}
