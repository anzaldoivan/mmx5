#include "types.h"

extern void func_8002D6FC(u8* obj);
extern u8* func_8002D1A4();
extern void func_80017248(u8* obj);
extern s32 func_8002DF54(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D800(u8* a0);
extern void func_8002D89C(u8*);
extern u8 D_8009A197;

void func_800EF848_ovl09(u8* o) {
    u8* c;
    u8* p;
    s32 d;
    s16 a;
    s16 b;

    p = *(u8**)(o + 0x7C);
    if (*(s8*)(p + 4) == 2 || *(s8*)(p + 7) == 0) {
        func_8002D6FC(o);
        return;
    }
    if (D_8009A197 == 0) {
        c = func_8002D1A4();
        if (c != 0) {
            a = *(s16*)(o + 0xE);
            b = *(s16*)(p + 0xE);
            d = a - b;
            if (d >= 0 ? d >= 0x30 : b - a >= 0x30) {
                if (*(s8*)(o + 5) == 0) {
                    p[7]++;
                    c[0] = 0x41;
                    c[1] = 0x16;
                    *(u16*)(c + 0x40) = *(u16*)(p + 0x40);
                    *(u16*)(c + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
                    *(s32*)(c + 0x3C) = *(s32*)(p + 0x3C);
                    c[0x14] = p[0x14];
                    *(s32*)(c + 0x8) = *(s32*)(p + 0x8);
                    *(s32*)(c + 0xC) = *(s32*)(p + 0xC) + 0x110000;
                    *(s32*)(c + 0x30) = *(s32*)(p + 0x30);
                    *(s32*)(c + 0x24) = 0xFFFA0000;
                    *(u8**)(c + 0x7C) = p;
                    c[2] = 0;
                    *(s32*)(c + 0x20) = 0;
                    o[5] = 1;
                }
            }
        }
        func_80017248(o);
        func_8002DF54(o);
        if (o[0x70] & 8) {
            if (*(s16*)(o + 0x88) == 0x12) {
                o[0x16] = 0;
                *(s32*)(o + 0x24) = 0;
                *(s32*)(o + 0x68) = 0;
                *(s32*)(o + 0x50) = 0;
                *(u16*)(o + 0xE) = (*(u16*)(o + 0xE) & 0xFFF0) | 8;
                func_800171E8(o, 3);
                (*(s16*)(o + 0x88))--;
            }
        }
        if (*(s16*)(o + 0x88) != 0x12) {
            if (--(*(s16*)(o + 0x88)) == 0) {
                o[4] = 2;
            }
        }
    }
    func_800317B8(o);
    if (func_8002D800(o) == 0) {
        func_8002D89C(o);
        return;
    }
    o[4] = 2;
}
