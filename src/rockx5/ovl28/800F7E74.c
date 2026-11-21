#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FE74C_ovl28[];
extern u8 D_800FE754_ovl28[];
extern u8 D_800FE758_ovl28[];
extern u8 D_80074E40[];

void func_800F7E74_ovl28(u8* o) {
    u8* p;
    u8* g;
    s32 e;
    s32 x;
    s32 ang;

    p = *(u8**)(o + 0x7C);
    *(u16*)(o + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(o + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(o + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(o + 0x3C) = *(s32*)(p + 0x3C);
    o[0x14] = 0;
    o[0x16] = 1;
    o[0x15] = p[0x15];
    o[0x67] = 0;
    o[0x3] = 0;
    *(u8**)(o + 0x68) = D_800FE74C_ovl28;
    *(u8**)(o + 0x50) = D_800FE754_ovl28;
    *(u8**)(o + 0x54) = D_800FE758_ovl28;
    *(u8**)(o + 0x58) = D_80074E40;
    if (o[0x15] == 0) {
        *(u16*)(o + 0xA) = *(u16*)(p + 0xA) - 0x1E;
    } else {
        *(u16*)(o + 0xA) = *(u16*)(p + 0xA) + 0x1E;
    }
    x = *(s16*)(o + 0xA);
    e = *(u16*)(*(u8**)(o + 0x7C) + 0xE) - 0xA;
    g = g_Player;
    *(u16*)(o + 0xE) = e;
    ang = (*(s16*)(g + 0xA) >= x) << 6;
    if (o[0x15] == ang) {
        x = *(s16*)(g + 0xA) - x;
    } else {
        x = x - *(s16*)(g + 0xA);
    }
    ang = (s16)ratan2(*(s16*)(g + 0xE) - (s16)e, x);
    if (ang <= 0) {
        if (ang >= -0x3FF) {
            if (ang < -0x200) {
                ang = -0x200;
            }
        } else if (ang >= -0x5FF) {
            ang = -0x600;
        }
    } else if (ang < 0x400) {
        ang = 0;
    } else {
        ang = -0x800;
    }
    *(s32*)(o + 0x20) = rcos(ang) << 6;
    *(s32*)(o + 0x24) = -rsin(ang) << 6;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x5C] = 1;
    o[0x60] = 8;
    set_animation(o, 0xE);
    *(s32*)(o + 0x8C) = 0;
    o[0x5] = 0;
    o[0x4]++;
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FE750_ovl28[];

void func_800F8040_ovl28(u8* o) {
    s8 st;
    s8 tl;
    s16 dx;
    s16 dy;
    s16 ang;
    u8* p;
    u8* q;
    u8* g;
    u8* g2;
    u8* g3;
    u8* g4;

    func_800317B8(o);
    if (func_80031DD0(o) < 0) {
        ((s32(*)())func_8004FD24)(o);
        if (*(s8*)(o + 5) == 0) {
            p = *(u8**)(o + 0x7C);
            p[7]++;
        }
        o[4] = 2;
        return;
    }
    st = *(s8*)(o + 5);
    switch (st) {
    case 0:
        g = g_Player;
        dx = (*(s16*)(g + 0xA) - *(s16*)(o + 0xA) < 0)
                 ? *(s16*)(o + 0xA) - *(s16*)(g + 0xA)
                 : *(s16*)(g + 0xA) - *(s16*)(o + 0xA);
        g2 = g_Player;
        dy = (*(s16*)(g2 + 0xE) - *(s16*)(o + 0xE) >= 0)
                 ? *(s16*)(g2 + 0xE) - *(s16*)(o + 0xE)
                 : *(s16*)(o + 0xE) - *(s16*)(g2 + 0xE);
        if (o[0x70] != 0 || dx + dy < 0x30) {
            q = *(u8**)(o + 0x7C);
            q[7]++;
            *(u8**)(o + 0x68) = D_800FE750_ovl28;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(u32*)(o + 0x8C) = 0;
            o[5]++;
        }
        break;
    case 1:
        if (++*(u32*)(o + 0x8C) == 0x78) {
            g3 = g_Player;
            if (*(s16*)(g3 + 0xA) < *(s16*)(o + 0xA)) {
                o[0x15] = 0;
            } else {
                o[0x15] = 0x40;
            }
            g4 = g_Player;
            ang = ratan2(*(s16*)(g4 + 0xE) - *(s16*)(o + 0xE),
                         *(s16*)(g4 + 0xA) - *(s16*)(o + 0xA));
            *(s32*)(o + 0x20) = rcos(ang) << 6;
            *(s32*)(o + 0x24) = -rsin(ang) << 6;
            *(u32*)(o + 0x8C) = 0;
            o[0x70] = 0;
            o[5]++;
        }
        break;
    case 2:
        if (++*(u32*)(o + 0x8C) >= 2 && o[0x70] != 0) {
            o[4] = 2;
        }
        break;
    }
    tl = *(s8*)(*(u8**)(o + 0x7C) + 4);
    if (tl == 2) {
        o[4] = tl;
    }
    func_8002D9EC(o, 0x20, 0x20);
    animate_object(o);
    move_object(o);
}
