#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D0E4(void);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);
extern s32 func_8002E024(void*, void*);
extern void func_8002E058(void*, s32);
extern void func_800F2F28_ovl06(u8* obj);
extern s32 D_8009A420;

void func_800F3198_ovl06(u8* o) {
    u8* p;
    s32 r;
    u8 a;
    u8 b;

    if (*(s16*)(o + 0x88) != 0) {
        *(s16*)(o + 0x88) = *(s16*)(o + 0x88) - 1;
        *(s32*)(o + 0x84) = 0;
    }
    if (!(D_8009A420 & 1) && *(s16*)(o + 0x88) == 0) {
        if (++*(s32*)(o + 0x84) >= 0x1E0) {
            *(s16*)(o + 0x88) = 0x3C;
        }
        func_800F2F28_ovl06(o);
        p = *(u8**)(o + 0x8C);
        if (p != 0) {
            r = func_8002E024(o, p);
            a = o[0x90];
            if (((a - r) & 0x1F) >= 2) {
                o[0x90] = ((u32)((r - a) & 0x1F) >= 0x10) ? a - 2 : a + 2;
                o[0x90] =
                    *(volatile u8*)(o + 0x90) &
                    0x1F; // !FAKE: volatile reload keeps the lbu after the sb
            }
            func_8002E058(o, o[0x90]);
            *(s32*)(o + 0x20) = *(s32*)(o + 0x20) * 6;
            *(s32*)(o + 0x24) = *(s32*)(o + 0x24) * 6;
        }
    }
    if (*(s16*)(o + 0x8A) == 0) {
        p = func_8002D0E4();
        if (p != 0) {
            a = o[0];
            p[1] = 0x16;
            p[2] = 0;
            p[0] = a;
            *(u16*)(p + 0xA) = *(u16*)(o + 0xA);
            *(u16*)(p + 0xE) = *(u16*)(o + 0xE);
            *(s32*)(p + 0x30) = *(s32*)(o + 0x30);
            *(u16*)(p + 0x40) = *(u16*)(o + 0x40);
            *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(o + 0x42);
            b = o[0x16];
            *(u8**)(p + 0x50) = o;
            p[0x16] = b;
            p[0x15] = o[0x15];
        }
        *(s16*)(o + 0x8A) = 1;
    } else {
        *(s16*)(o + 0x8A) = *(s16*)(o + 0x8A) - 1;
    }
    func_80017248(o);
    func_8002DED4(o);
    if (func_8002D938(o, 0x20, 0x20) == 0 && *(s8*)(o + 0x98) == 0) {
        func_8002D9EC(o, 0x10, 0x10);
        return;
    }
    o[4] = 2;
    o[3] = 0;
    *(s32*)(o + 0x50) = 0;
}
