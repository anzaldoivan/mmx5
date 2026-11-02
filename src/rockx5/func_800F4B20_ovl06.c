#include "types.h"

extern s32 func_80030AE4(u8*, s16, s16);
extern u8 D_8009A0A0[];

void func_800F4B20_ovl06(u8* o) {
    u8* p;
    u8* q;
    u8* u;
    u8* t;
    s32 d;
    s16 x;
    s16 y;
    u32 i;
    s32 r;

    if (*(s8*)(o + 5) < 2) {
        return;
    }
    p = D_8009A0A0;
    d = *(s16*)(o + 0xA) - *(s16*)(p + 0xA);
    if ((d >= 0) ? (d < 0x41) : (*(s16*)(p + 0xA) - *(s16*)(o + 0xA) < 0x41)) {
        o[0x87] = 1;
    } else if (*(s8*)(o + 2) == 0) {
        q = D_8009A0A0;
        d = *(s16*)(o + 0xA) - *(s16*)(q + 0xA);
        if ((d >= 0) ? (d >= 0x98)
                     : (*(s16*)(q + 0xA) - *(s16*)(o + 0xA) >= 0x98)) {
            o[0x88] = 1;
        }
        u = D_8009A0A0;
        if (*(s16*)(o + 0xA) - *(s16*)(u + 0xA) < 0) {
            o[0x8A] = 1;
        } else {
            o[0x8A] = 2;
        }
    } else {
        o[0x8A] = 0;
    }
    if (*(s8*)(o + 0x67) == 0 && !(*(s32*)(o + 0x84) & 0xFFFF0000) &&
        !(o[0x8D] & 8)) {
        t = *(u8**)(o + 0x68);
        y = *(u16*)(o + 0xE) + t[3];
        if (o[0x70] & o[0x8A]) {
            if (o[0x15] == 0) {
                x = *(u16*)(o + 0xA) - t[2];
            } else {
                x = *(u16*)(o + 0xA) + (t[2] + 1);
            }
            y--;
            for (i = 0; i < 5; i++) {
                r = func_80030AE4(o, x, y) & 0xFF;
                y -= 16;
                if (r == 0) {
                    i = 5;
                    o[0x86] = 1;
                }
            }
            if (o[0x86] == 0) {
                o[0x8A] = 0;
                o[0x86] = 0;
            }
        } else {
            r = func_80030AE4(o, *(s16*)(o + 0xA), y + 2) & 0xFF;
            if (r == 0) {
                o[0x86] = 1;
            }
        }
    }
}
