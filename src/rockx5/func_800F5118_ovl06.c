#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D0E4(void);
extern void func_8002DED4(u8* obj);
extern s16 D_8009A0AA;
extern u8 D_800FE924_ovl06[];

static inline u8 func_800F5118_face(u8* p) {
    if (*(s8*)(p + 2) == 0) {
        u8 t = p[0x8A];
        if (t != 0) {
            if (t & 1) {
                p[0x15] = 0x40;
            } else {
                p[0x15] = 0;
            }
            return 1;
        }
    } else {
        if (*(s16*)(p + 0xA) - D_8009A0AA < 0) {
            p[0x15] = 0x40;
        } else {
            p[0x15] = 0;
        }
    }
    return 0;
}

void func_800F5118_ovl06(u8* p, u8* c) {
    s32 v;
    s32 six;

    c = (u8*)(u32)
        p[6]; // !FAKE: one a1 local for the state byte and the child (param c)
    if (*(s8*)(p + 6) == 0) {
        p[6] = (s32)c + 1;
        *(s32*)(p + 0x24) = 0x58000;
        *(s32*)(p + 0x2C) = 0x4200;
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x28) = 0;
        p[0x67] = 1;
        func_800171E8(p, 2);
        six = 6;
        p[0x70] &= 0xF7;
        c = func_8002D0E4();
        if (c != 0) {
            c[0] = p[0];
            c[1] = 0xC;
            c[2] = six;
            *(s32*)(c + 0x8) = *(s32*)(p + 0x8);
            *(s32*)(c + 0xC) = *(s32*)(p + 0xC);
            *(s32*)(c + 0x30) = *(s32*)(p + 0x30);
            *(s16*)(c + 0x40) = *(s16*)(p + 0x40);
            *(s32*)(c + 0x3C) = *(s32*)(p + 0x3C);
            *(s16*)(c + 0x42) = *(s16*)(p + 0x42) & 0x7FFF;
            c[0x16] = p[0x16];
            c[0x15] = p[0x15];
            *(u8**)(c + 0x50) = p;
        }
        *(u8**)(p + 0x50) = D_800FE924_ovl06;
        p[0x60] = six;
    }
    if (p[0x87] == 0) {
        if (p[0x8D] & 2) {
            return;
        }
        *(s32*)(p + 0x20) = 0;
        if (func_800F5118_face(p)) {
            v = *(s16*)(p + 0x84) << 8;
            if (p[0x15] == 0) {
                v = -v;
            }
            *(s32*)(p + 0x20) = v;
        }
        if (!(p[0x70] & 4) && *(s32*)(p + 0x24) >= 0) {
            func_8002DED4(p);
            return;
        }
        p[5] = 4;
        p[6] = 0;
    } else {
        p[5] = 0xA;
        p[6] = 0;
    }
}
