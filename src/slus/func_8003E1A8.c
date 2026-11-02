#include "types.h"

extern void func_8003CE64(u8* obj);
extern void func_8003F250(u8* p);
extern void func_8003EE38(u8* p);
extern void func_8003DF20(u8* p);
extern void func_8003B33C(u8*, s32);
extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern s8 D_800D1C1C;

s32 func_8003E1A8(u8* p) {
    u8 t;
    s32 m;

    if (*(s8*)(p + 0x2) != 0) {
        return 0;
    }
    if (p[0x92] != 0) {
        return 0;
    }
    if (*(s16*)(p + 0xA8) != *(s16*)(p + 0x148)) {
        return 0;
    }
    if (*(s8*)(p + 0x14B) < 0) {
        return 0;
    }
    if (!(*(u16*)(p + 0x80) & 0x40)) {
        return 0;
    }
    t = p[0xFA];
    if ((u32)(t - 2) >= 3) {
        return 0;
    }
    if (t == 4) {
        if (*(s8*)(p + 0x86) != 0) {
            return 0;
        }
        m = 2;
        if (p[0x15] != 0) {
            m = 1;
        }
        if (p[0x89] & m) {
            return 0;
        }
    }
    func_8003CE64(p);
    if (*(s8*)(p + 0x2) == 0) {
        if (*(s8*)(p + 0x93) == 6) {
            if (p[0x91] != 0) {
                p[0x91] = 1;
            }
            if (p[0x92] != 0) {
                p[0x92] = 1;
            }
        }
        p[0x93] = 0;
        func_8003F250(p);
        func_8003EE38(p);
        func_8003DF20(p);
    }
    p[0x67] = 1;
    p[0x61] = 0;
    p[0xA4] = 0;
    p[0x154] = 0;
    p[0x14B] = 0;
    if (p[0xFA] != 4) {
        *(s16*)(p + 0xA8) = 0;
    }
    t = p[0xFA];
    if (t == 2) {
        if (p[0x89] & 8) {
            func_8003B33C(p, 0xAE);
        } else {
            func_8003B33C(p, 0xB1);
        }
        p[0x5] = 0x24;
        func_8003D4C0(1, 0x1B, 7, 0);
        p[0x86] = 5;
        p[0xF4] = 0;
        *(s32*)(p + 0x68) = 0;
    } else if (t == 3) {
        func_8003B33C(p, 0xB4);
        p[0x5] = 0x25;
        p[0x86] = 5;
        p[0xF4] = 0;
        *(s32*)(p + 0x68) = 0;
    } else {
        func_8003B33C(p, 0x6A);
        p[0x5] = 0x22;
        p[0x84] = 0;
        p[0x8C] = 0;
        p[0x86] = 5;
        p[0xF4] = 0x18;
        if (p[0x15] != 0) {
            *(s32*)(p + 0x20) = 0x28000;
        } else {
            *(s32*)(p + 0x20) = -0x28000;
        }
        *(s32*)(p + 0x28) = 0;
        *(s32*)(p + 0x24) = 0x38000;
        *(s32*)(p + 0x2C) = *(s32*)(p + 0x110);
    }
    p[0x7A] = 1;
    p[0xF3] = 1;
    D_800D1C1C = 1;
    p[0x6] = 0;
    return 1;
}
