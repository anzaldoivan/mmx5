#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_8003DF20(u8* p);
extern void func_8003EE38(u8* p);
extern void func_8003C5D8(u8* obj);
extern u8* find_free_visual_obj(void);
extern s32 func_8002B5B4(s32);
extern u8 D_80093E10[];
extern u8 D_80078D60[];
extern u8 D_8007A194[];
extern u16 D_80074864[];
extern s8 D_80074834[];
extern u32* D_80098118;

void func_8003BAC8(void) {
    u8* p = g_Player;
    u8* q = g_playthrough_state.u;
    u8* e;
    u8* f;
    u8* g;
    u8* prev;
    u8* o;
    u8* n;
    u32 i;
    s32 k;
    s32 a;
    s32 b;
    s32 h;
    s32 m;
    s8* t;
    s8* tb;
    u8 b14;

    g_Player[0] = 1;
    p[3] = 0;
    p[0x14] = 0;
    p[0xF8] = 0;
    p[0xF0] = 0;
    *(s32*)(p + 0x150) = 0;
    q[0x10D] = 0;
    q[0x10E] = 0;
    *(s32*)(p + 0x100) = 0x8000;
    *(s32*)(p + 0x104) = 0x20000;
    *(s32*)(p + 0x108) = 0x5D000;
    {
        // !FAKE: register pin for the constant's register
        register s32 c asm("$8") = -0x68000;
        *(s32*)(p + 0x10C) = c;
    }
    *(s32*)(p + 0x110) = *(s32*)(p + 0x144) = 0x4200;
    *(s32*)(p + 0x114) = 0x68000;
    *(s32*)(p + 0x118) = 0x42000;
    *(s32*)(p + 0x11C) = -0x3000;
    *(s32*)(p + 0x120) = -0x17000;
    *(s32*)(p + 0x124) = 0x5A000;
    *(s32*)(p + 0x128) = 0x10000;
    *(s32*)(p + 0x12C) = 0x18000;
    *(s32*)(p + 0x130) = 0x20000;
    *(s32*)(p + 0x134) = 0x20000;
    *(s32*)(p + 0x138) = 0x18000;
    *(s32*)(p + 0x13C) = 0x42000;
    *(s32*)(p + 0x140) = 0x42000;
    p[2] = q[0x44];

    switch (((s8*)q)[0x1E]) {
    case -2:
    case 0:
        t = (s8*)(q + 0x53);
        p[0x5E] = p[0x5D] = p[0x5C] = (q + ((s8*)p)[2])[0x47];
        *(s16*)(p + 0x148) = t[((s8*)p)[2]] * 6;
        for (i = 0; i < 16; i++) {
            ((u16*)(p + 0xA8))[i] = *(u16*)(p + 0x148);
        }
        p[0xFB] = 0;
        break;
    case -1:
        p[0x5E] = p[0x5D] = p[0x5C] = q[0x46];
        for (i = 0; i < 16; i++) {
            ((u16*)(p + 0xA8))[i] = ((u16*)(q + 0x56))[i];
        }
        t = (s8*)(q + 0x53);
        p[0x93] = q[0x7A];
        m = t[((s8*)p)[2]];
        p[0xFB] = q[0xC1];
        *(s16*)(p + 0x148) = m * 6;
        func_8003DF20(p);
        func_8003EE38(p);
        break;
    }

    if (((s8*)p)[2] == 0) {
        *(u8**)(p + 0x30) = D_80078D60;
    } else {
        *(u8**)(p + 0x30) = D_8007A194;
    }
    *(s32*)(p + 0x38) = (s32)D_1F800014 + *(s32*)D_1F800014;
    *(u8**)(p + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[0];
    *(s16*)(p + 0x40) = 0x500;
    p[0x16] = 2;
    *(s16*)(p + 0x42) = 0x7800;
    p[0x49] = 3;
    func_8003C5D8(p);

    f = D_8009A2F8.r[0];
    for (i = 0; i < 3; i++) {
        f[0] = 0x11;
        f[2] = i;
        f[0x14] = p[0x14];
        *(s32*)(f + 0x38) = *(s32*)(p + 0x38);
        *(s32*)(f + 0x3C) = *(s32*)(p + 0x3C);
        *(u16*)(f + 0x40) = *(u16*)(p + 0x40);
        *(u16*)(f + 0x42) = D_80074864[(s8)i];
        f[0x16] = 4;
        if (i != 0) {
            *(u8**)(f + 0x50) = prev;
        } else {
            *(u8**)(f + 0x50) = g_Player;
        }
        prev = f;
        f += 0x60;
    }

    g = D_800942A8.u;
    for (i = 0; i < 2; i++) {
        g[0] = 0x21;
        g[2] = i;
        g[0x14] = p[0x14];
        *(s32*)(g + 0x38) = 0;
        *(u8**)(g + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[0x1C];
        *(u32***)(g + 0x30) = g_visual_animation_tables.p;
        *(s16*)(g + 0x40) = 0;
        *(s16*)(g + 0x42) = 0x7802;
        g[0x16] = 2;
        g[0x15] = 0;
        g += 0x50;
    }

    if (((s8*)p)[2] == 0) {
        h = g_playthrough_state.u[0x49];
        if (h == 3) {
            g[0] = 0x21;
            g[2] = 2;
            *(s32*)(g + 0x38) = 0;
            g[0x14] = p[0x14];
            *(u8**)(g + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[8];
            *(u32***)(g + 0x30) = g_visual_animation_tables.p;
            *(s16*)(g + 0x40) = 0;
            *(s16*)(g + 0x42) = 0x7803;
            g[0x16] = 2;
            g[0x15] = 0;
            g[3] = 0;
            set_animation(g, 0x2A);
        } else if (h == 2) {
            g[0] = 0x21;
            g[2] = 3;
            *(s32*)(g + 0x38) = 0;
            g[0x14] = p[0x14];
            *(u8**)(g + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[8];
            *(u32***)(g + 0x30) = g_visual_animation_tables.p;
            *(s16*)(g + 0x40) = 0;
            *(s16*)(g + 0x42) = 0x7802;
            g[0x16] = h;
            g[0x15] = 0;
            g[3] = 0;
            set_animation(g, 0x2A);
        }
    }

    if (((s8*)q)[0xC] == 7) {
        for (i = 0; i < 4; i++) {
            n = find_free_visual_obj();
            if (n != 0) {
                n[0] = 0x41;
                n[1] = 7;
                n[2] = i;
            }
        }
    }

    tb = D_80074834;
    e = (u8*)&tb[((s8*)q)[0xD] + ((s8*)q)[0xC] * 2];
    if (*(s8*)e != 0) {
        k = *e;
        o = D_80093E10;
        o[0] = 0x41;
        o[0x16] = 1;
        o[0x14] = p[0x14];
        *(u16*)(o + 0x40) = D_80098118[func_8002B5B4(k)] >> 7;
        *(s32*)(o + 0x3C) =
            (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(k)];
        a = func_8002B5B4(k);
        b = func_8002B5B4(k);
        *(s16*)(o + 0x42) =
            ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
        *(u32***)(o + 0x30) = g_visual_animation_tables.p;
        if (k == 0x19) {
            set_animation(o, 0x28);
        } else {
            set_animation(o, 0x29);
        }
        o[0x15] = 0;
    } else {
        D_80093E10[0] = 0;
    }

    D_8009A1F8.u[0x44] = 0;
    D_8009A1F8.u[0x98] = 0;
    D_8009A1F8.u[0xEC] = 0;
}
