#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/sound.h"

extern void LoadImage(void*, void*);
extern void func_80013288(int);
extern u8 D_80070FE8[];
extern u8 D_8009A427;
extern u8 D_80071040;

void func_8001F378(u8* arg0) {
    u8* o;
    u8* obj;
    u8* p;
    u8 i;
    s32 one;

    func_8002C50C();
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x40;
        *(s16*)(o + 0xA) = 0xF0;
        *(s16*)(o + 0xE) = 0x90;
    }
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x3E;
        *(s16*)(o + 0xA) = 0xF0;
        *(s16*)(o + 0xE) = 0x50;
    }
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x3F;
        *(s16*)(o + 0xA) = 0xF0;
        *(s16*)(o + 0xE) = 0x30;
    }
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x3D;
        *(s16*)(o + 0xA) = 0xE8;
        *(s16*)(o + 0xE) = 0xB0;
    }
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x3C;
        *(s16*)(o + 0xA) = 0xF8;
        *(s16*)(o + 0xE) = 0xB0;
    }
    p = D_80070FE8;
    i = 0;
    arg0[3] = 0;
    D_8009A427 = 0;
    one = 1;
    if (*p != 0) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = one;
            obj[1] = 0x20;
            *(u8**)(obj + 0x50) = p;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    } else {
        p++;
    }
    while (*p != 0xFF) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x1F;
            obj[2] = *p++;
            obj[7] = i++;
            *(u16*)(obj + 0xE) = *p++;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    }
    *(u16*)(arg0 + 8) = p[1];
    D_8009A1F8.u[3] = 0;
    D_8009A1F8.u[0x57] = 0;
    D_8009A1F8.u[0xAB] = 0;
    LoadImage(&D_80071040, D_801F3000 + D_801F3004);
    func_80013288(8);
    arg0[1] = arg0[1] + 1;
}

extern void func_800132F8(s8 arg);
extern void func_800211C4(void*, s32);
extern void func_80016D1C(u8 arg0);
extern s32 func_80017D88(void);
extern void func_800177B0(s32, s32);
extern u8 D_800D1599;
extern u8 D_8006FADD;
extern u8 D_8006FADC;
extern u8 D_800D1F28[];
extern u8 D_80071048[];

void func_8001F608(u8* arg0) {
    u8 old;
    u8 t;
    u16 c;
    u16 d;
    u16 e;
    u8* b = D_8009A420;
    u8* q;
    u8* r;

    if (((s8*)b)[4] != 0) {
        return;
    }
    if ((g_pad1_buttons[2] & 0x10) && D_8009A420[7] != 4) {
        func_800132F8(8);
        D_8009A420[7] = 5;
        arg0[1]++;
        return;
    }
    if ((g_pad1_buttons[2] & 0x40) &&
        (D_8009A420[7] == 2 || D_8009A420[7] == 5)) {
        play_sound(0, 0x22, 0);
        func_800132F8(8);
        arg0[1]++;
        return;
    }
    old = D_8009A420[7];
    func_800211C4(&D_8009A420[7], *(s16*)(arg0 + 8));
    if ((g_pad1_buttons[2] & 0xA040) && D_8009A420[7] == 3) {
        play_sound(0, 0xC, 0);
        D_800D1599 ^= 1;
        func_80016D1C(D_800D1599);
    }
    if ((g_pad1_buttons[2] & 0xA040) && D_8009A420[7] == 1) {
        play_sound(0, 0xC, 0);
        D_8006FADD ^= 1;
    }
    c = g_pad1_buttons[2];
    if ((c & 0xA000) && D_8009A420[7] == 0) {
        if (c & 0x8000) {
            play_sound(0, 0xC, 0);
            if (D_8006FADC != 0) {
                D_8006FADC--;
            } else {
                D_8006FADC = 2;
            }
        } else if (c & 0x2000) {
            play_sound(0, 0xC, 0);
            if (D_8006FADC < 2) {
                D_8006FADC++;
            } else {
                D_8006FADC = 0;
            }
        }
    }
    d = g_pad1_buttons[2];
    if ((d & 0xA050) && D_8009A420[7] == 4) {
        q = D_800D1F28;
        t = q[3];
        if (d & 0x8000) {
            if (t != 0) {
                q[3] = t - 1;
            }
        } else if (d & 0x2000) {
            if ((s8)t < 30) {
                q[3] = t + 1;
            }
        }
        r = D_800D1F28;
        if (t != ((s8*)r)[3]) {
            play_sound(0, 0xC, 0);
        }
        e = g_pad1_buttons[2];
        if (e & 0x10) {
            func_80017D88();
        } else if (e & 0x40) {
            func_80017D88();
            func_800177B0(D_80071048[((s8*)r)[3]], 0x7F);
        }
    }
    if (D_8009A420[7] != 4 && old == 4) {
        func_80017D88();
    }
}
