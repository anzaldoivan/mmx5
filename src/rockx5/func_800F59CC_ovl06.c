#include "types.h"

extern void func_800F4B20_ovl06(u8* o);
extern s32 func_8002FB58(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern u8* func_8002D0E4(void);
extern s32 func_8002D800(u8* a0);
extern void func_8002D89C(u8*);
extern u8 D_8009A197;
extern u8 D_800FE928_ovl06[];
extern void* D_800FE930_ovl06[];

void func_800F59CC_ovl06(u8* o) {
    s32 r;
    u8 t;
    s32 s;

    if (D_8009A197 == 0) {
        *(s32*)(o + 0x18) = *(s32*)(o + 0x8);
        *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
        t = o[0x8B];
        if (t != 0) {
            o[0x8B] = t - 1;
        }
        func_800F4B20_ovl06(o);
        s = *(s8*)(o + 5);
        if (s >= 2) {
            if (s == 6) {
            } else if (s == 7) {
            } else if (s != 11 && o[0x88] != 0 && !(o[0x8D] & 8) &&
                       *(s8*)(o + 0x67) == 0 && o[0x86] == 0) {
                o[5] = 6;
                o[6] = 0;
            }
        }
        ((void (*)(u8*))D_800FE930_ovl06[*(s8*)(o + 5)])(o);
    }
    func_8002FB58(o);
    func_800317B8(o);
    r = func_80031DD0(o);
    if (r < 0) {
        func_8004FD24(o);
        func_8004D4F4(7, D_800FE928_ovl06, o);
        func_80054440(o, 0x11);
        o[4] = 2;
        o[5] = 0;
    } else if (r != 0) {
        u8* c = func_8002D0E4();
        if (c != 0) {
            c[0] = o[0];
            c[1] = 0xC;
            c[2] = 8;
            *(s32*)(c + 0x8) = *(s32*)(o + 0x8);
            *(s32*)(c + 0xC) = *(s32*)(o + 0xC);
            *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
            *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
            *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
            *(s16*)(c + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
            c[0x16] = o[0x16];
            c[0x15] = o[0x15];
            *(u8**)(c + 0x50) = o;
        }
    }
    if (func_8002D800(o) == 0) {
        func_8002D89C(o);
        return;
    }
    o[4] = 3;
    o[5] = 0;
}
