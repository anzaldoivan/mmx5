#include "types.h"
#include "mmx5/ovl04.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern s32 func_800326BC(u8* a0);
extern void func_800F64F8_ovl04(s32, void*, u8*, s32);
extern void func_80032F70(u8* a0);
extern s32 func_8003240C(u8* a0);
extern u8 D_801026A0_ovl04[];
extern void* D_801026B4_ovl04[];

void func_800F73B4_ovl04(u8* o) {
    s32 lo;
    s32 hi;
    s32 spd;
    u8* p;
    u8* q;
    s32 t;
    s32 c;
    u8* g;
    u8* h;
    u8* r;

    if (D_800D1C0C.s != 12) {
        lo = 0x1540;
        hi = 0x16E0;
    } else {
        lo = 0x430;
        hi = 0x5D0;
    }
    spd = 0xB0;
    c = ((signed char*)*(u8**)(o + 0x7C))[4];
    p = *(u8**)(o + 0x7C);
    if (c == 2 || (c == 3 && ((signed char*)p)[5] != 2)) {
        play_sound(2, 0x15, o);
        func_800F64F8_ovl04(3, D_801026A0_ovl04, o, 0);
        o[4] = 2;
        return;
    }
    g = g_Player;
    if (((signed char*)g)[0xF3] != 0 && (g[0xFA] == 2 || g[0xFA] == 3)) {
        func_800326BC(o);
        return;
    }
    if (((signed char*)o)[2] < 100) {
        p = *(u8**)(o + 0x7C);
        if (((signed char*)p)[5] == 2) {
            play_sound(2, 0x15, o);
            func_800F64F8_ovl04(4, D_801026A0_ovl04, o, 0);
            o[4] = 2;
            return;
        }
        if (((signed char*)p)[0x90] > 0) {
            t = *(s32*)(p + 0x98);
            *(s32*)(o + 0x20) = t;
            if (t > 0xFFFF) {
                *(s32*)(o + 0x20) = 0x10000;
            }
        } else {
            *(s32*)(o + 0x20) = 0xFFFF0000;
        }
        q = *(u8**)(o + 0x7C);
        if (((signed char*)q)[5] == 3 || ((signed char*)q)[5] == 6 ||
            (*(u32*)(q + 4) & 0xFFFF00) == 0x30500) {
            *(s32*)(o + 0x20) = 0;
            if (*(s16*)(o + 0xA) <= lo || *(s16*)(o + 0xA) >= hi) {
                clear_object_slot(o);
                return;
            }
        }
    }
    move_object(o);
    ((void (*)(u8*))D_801026B4_ovl04[((signed char*)o)[6]])(o);
    func_800326BC(o);
    func_80032F70(o);
    animate_object(o);
    if (o[0x83] == 0 && *(s16*)(o + 0xA) >= hi - 0x40) {
        o[0x83] = 1;
        *(s32*)(o + 0x54) = 0;
        play_sound(2, 0x15, o);
        func_800F64F8_ovl04(4, D_801026A0_ovl04, o, 0);
    }
    if (((signed char*)o)[0x60] == 0x7F) {
        func_800317B8(o);
    }
    if (D_80101D60_ovl04[o[0x82]][((signed char*)o)[2]].x3 == 0 &&
        ((signed char*)o)[2] < 100) {
        r = g_Player;
        spd = 0x80;
        if (((*(s16*)(r + 0xA) - *(s16*)(o + 0xA)) < 0
                 ? (*(s16*)(o + 0xA) - *(s16*)(r + 0xA))
                 : (*(s16*)(r + 0xA) - *(s16*)(o + 0xA))) > 0x40) {
            if (is_off_screen(o, 0x80, 0x20) == 0) {
                ((s32(*)())func_8002D89C)(o);
                if (o[0x83] != 0) {
                    o[3] = 0;
                }
                return;
            }
            clear_object_slot(o);
            return;
        }
    }
    h = g_Player;
    if (h[0xF8] == 0) {
        func_8003240C(o);
    }
    if (is_off_screen(o, spd, 0x20) == 0) {
        ((s32(*)())func_8002D89C)(o);
        if (o[0x83] != 0) {
            o[3] = 0;
        }
        return;
    }
    clear_object_slot(o);
}

void func_800F7738_ovl04(u8* o) {
    u8* c;
    u8* e;
    s32 i;
    s8 n;
    Ent6E78* b;

    b = D_80101D60_ovl04[0];
    n = o[2];
    e = (u8*)&b[o[0x82] * 37 + n];
    if (e[2] == 0) {
        o[6] = 2;
        return;
    }
    if (n == 0) {
        return;
    }
    if (*(s16*)(o + 0xA) - *(s16*)(o + 0x80) < 0x20) {
        return;
    }
    for (i = 0;
         i < (u8)(*(u32*)&D_80101D60_ovl04[0][o[0x82] * 37 + (s8)o[2]] >> 16);
         i++) {
        c = (u8*)func_8002CD14((Obj8002CD14*)o, 0);
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 7;
            *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
            *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
            *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
            *(u16*)(c + 0x42) = *(u16*)(o + 0x42);
            c[2] = (u8)(o[2] - 1) - i;
            *(u16*)(c + 0xA) = *(u16*)(o + 0xA) - 0x20;
            *(s32*)(c + 0xC) = 0;
            *(s32*)(c + 0x20) = *(s32*)(o + 0x20);
            *(s32*)(c + 0x24) = 0;
            *(s32*)(c + 0x7C) = *(s32*)(o + 0x7C);
            c[0x82] = o[0x82];
            *(u16*)(c + 0x80) = *(u16*)(o + 0x80);
        }
        o[6] = 2;
    }
}
