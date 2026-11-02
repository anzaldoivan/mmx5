#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern s32 func_80030CBC(u8*);
extern void func_80038F18(u8*, s32);
extern void func_8003B33C(u8*, s32);
extern void func_8003CE10(u8*);

s32 func_800390A4(u8* p) {
    s32 r;
    s32 a;

    if (*(s8*)(p + 0xD3) != 0) {
        return 0;
    }
    if (p[0xF6] != 0) {
        if (--p[0xF6] != 0) {
            return 0;
        }
    }
    if (!(*(u16*)(p + 0x7C) & 4)) {
        return 0;
    }
    r = func_80030CBC(p);
    if (r == 0x2E) {
        if (*(s8*)(p + 0x8E) != 0 && *(s8*)(p + 2) == 0) {
            func_8003B33C(p, 0x90);
        } else {
            func_80016490(0, 0x26, p);
            *(s8*)(p + 0x8E) = 0;
            func_8003B33C(p, 0xA0);
        }
        *(s16*)(p + 0x8) = 0;
        *(s16*)(p + 0xC) = 0;
        p[0x5] = 0x1B;
        p[0x6] = 0;
        *(s32*)(p + 0x20) = 0;
        *(u16*)(p + 0xA) = (*(u16*)(p + 0xA) & 0xFFF0) + 8;
        func_8003CE10(p);
        return 1;
    } else {
        if ((u8)(r - 0x25) >= 9) {
            return 0;
        }
        if (*(s32*)(p + 0x24) > 0) {
            return 0;
        }
        if (*(s8*)(p + 0x8E) != 0 && *(s8*)(p + 2) == 0) {
            switch (r) {
            case 0x2D:
                a = 0;
                break;
            case 0x25 ... 0x28:
                a = 1;
                if (p[0x15] == 0) {
                    a = 2;
                }
                break;
            default:
                a = 2;
                if (p[0x15] == 0) {
                    a = 1;
                }
                break;
            }
            func_8003B33C(p, a | 0x94);
        } else {
            func_80016490(0, 0x26, p);
            switch (r) {
            case 0x2D:
                a = 0;
                break;
            case 0x25 ... 0x28:
                a = 1;
                if (p[0x15] == 0) {
                    a = 2;
                }
                break;
            default:
                a = 2;
                if (p[0x15] == 0) {
                    a = 1;
                }
                break;
            }
            func_8003B33C(p, a + 0xA3);
            *(s8*)(p + 0x8E) = 0;
        }
        p[0x5] = 0x1C;
        p[0x6] = 0;
        *(s32*)(p + 0x24) = 0;
        func_80038F18(p, r);
        func_8003CE10(p);
        return 1;
    }
}
