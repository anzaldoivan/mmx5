#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D078();
extern s32 func_8002B5B4(s32);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_8009A1F8[];
extern u8 D_8009A0A0[];

static inline void func_800EF2C8_ovl07_snd(s32 v) {
    D_8009A0A0[0xD8] = v;
    D_8009A0A0[6] = 0;
}

void func_800EF2C8_ovl07(u8* obj) {
    u8* p;
    u8* q;
    u8* e;
    s32 r;
    s16 d;

    e = D_8009A1F8;
    d = *(u16*)(obj + 0xA) - *(u16*)(e + *(s8*)(obj + 0x14) * 0x54 + 0xA);
    switch (*(s8*)(obj + 6)) {
    case 0:
        obj[6] = 1;
        *(s32*)(obj + 0x28) = 0x8000;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[0x7C] = 1;
        obj[0x15] = 0x40;
        func_80016490(5, 0x11, 0);
        func_800171E8(obj, 6);
        func_800EF2C8_ovl07_snd(0x47);
        p = func_8002D078();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x39;
            *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            r = func_8002B5B4(0x82);
            *(u16*)(p + 0x42) =
                ((r * 4 + 0x18) % 16) | ((((r + 6) / 4) + 0x1E0) << 6);
            p[0x16] = obj[0x16];
            *(u8**)(p + 0x7C) = obj;
            p[0x15] = obj[0x15];
        }
        break;
    case 1:
        if (__builtin_abs(*(s32*)(obj + 0x20)) > 0x7FFFF) {
            *(s32*)(obj + 0x20) = 0x80000;
            *(s32*)(obj + 0x28) = 0;
        }
        if (d >= 0xC0) {
            obj[6] = 2;
            *(s32*)(obj + 0x20) = 0x60000;
            *(s32*)(obj + 0x28) = -0x4000;
        }
        func_80017248(obj);
        break;
    case 2:
        if (d < 0x91) {
            obj[6] = 3;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            func_800171E8(obj, 7);
            func_800EF2C8_ovl07_snd(0x4B);
        }
        func_80017248(obj);
        break;
    case 3:
        if (*(s8*)(obj + 0x46) == 0) {
            obj[6] = 4;
        }
        func_80017248(obj);
        break;
    case 4:
        q = *(u8**)(obj + 0xA0);
        if (*(s8*)(q + 0) == 0 || *(s8*)(q + 5) == 3) {
            obj[5] = 1;
            obj[6] = 0;
        }
        func_80017248(obj);
        break;
    }
    func_8002DED4(obj);
}
