#include "types.h"

extern s32 func_80030A0C(u8* obj);
extern void func_8003B0AC(u8* obj);
extern void func_8003AFEC(u8* obj);
extern void func_8003B33C(u8*, s32);

s32 func_80039DB8(u8* obj) {
    s32 r;
    s32 t;

    r = func_80030A0C(obj);
    if (obj[0x89] & 8) {
        func_8003B0AC(obj);
        return 1;
    }
    if ((*(u16*)(obj + 0x7C) & 4) && r == 0x21) {
        func_8003AFEC(obj);
        return 1;
    }
    t = (u8)(r - 0x20) >= 2;
    if (*(u16*)(obj + 0x80) & 0x80) {
        t = 1;
    }
    if (t != 0) {
        func_8003B33C(obj, 0x1E);
        obj[5] = 0xE;
        obj[6] = 4;
        return 1;
    }
    return 0;
}
