#include "types.h"

extern s32 func_8003E6FC(void*, s8);
extern void func_8003CE10(u8*);
extern void func_8003B33C(u8*, s32);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_80041EF8(u8* obj);
extern u8 D_800D1DBA;

s32 func_80041A54(u8* o) {
    s8 st;

    if (((s8*)o)[2] == 0) {
        return 0;
    }
    if (((s8*)o)[0xD3] != 0) {
        return 0;
    }
    if (((s8*)o)[0x93] == 3 && ((s8*)o)[0xA6] == 0) {
        s32 r = func_8003E6FC(o, 3);
        if (*(s16*)(o + 0xAE) >= r) {
            return 0;
        }
    }
    if (!(*(u16*)(o + 0x80) & 0x20)) {
        return 0;
    }
    st = ((s8*)o)[0x93];
    if (st == 2) {
        return 0;
    }
    if (((s8*)o)[0x8E] != 0) {
        return 0;
    }
    if (D_800D1DBA == 0) {
        return 0;
    }
    if (st == 1) {
        return 0;
    }
    o[0x8E] = 1;
    o[0xCB] = 0;
    func_8003CE10(o);
    func_8003B33C(o, 0x6E);
    if (func_8002DF78() & 4) {
        func_8003CF74(o, 9);
    }
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[5] = 0x3E;
    o[6] = 0;
    func_80041EF8(o);
    return 1;
}
