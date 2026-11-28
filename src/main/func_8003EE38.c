#include "types.h"

extern void func_8003F4C4(u8* p, s32 arg);

void func_8003EE38(u8* p) {
    u8 kind;
    QByte
        v; // !FAKE: one-byte struct keeps the byte in a QImode pseudo (no promotion)

    if (*(s8*)(p + 0xF0) != 0) {
        p[0x94] = 0;
        p[0x95] = 0;
    } else {
        kind = p[0xFA];
        if (kind == 3) {
            p[0x94] = 0x2D;
            p[0x95] = 0x2D;
            if (*(s8*)(p + 0x9B) == 2) {
                p[0x94] = 0x2E;
            }
            if (*(s8*)(p + 0x9C) == 2) {
                p[0x95] = 0x2E;
            }
        } else {
            v.b = p[0x93];
            p[0x94] = v.b;
            if ((s8)v.b != 0) {
                if (*(s8*)(p + 0x9B) == 2 || ((*(s32*)(p + 0xFC) & 0x1000) &&
                                              (kind == 1 || kind == 4))) {
                    p[0x94] = v.b + 9;
                }
            } else {
                func_8003F4C4(p, 0);
            }
            p[0x95] = 0;
            func_8003F4C4(p, 1);
        }
    }
}
