#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

static inline u8* func_800F9AE0_spawn(u8* obj) {
    u8* p;

    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xB;
        *(u8**)(p + 0x7C) = obj;
        p[2] = 0;
    }
    return p;
}

void func_800F9AE0_ovl04(u8* obj) {
    u8* p;
    u8* d;
    u8* e;
    s32 ang;
    s8 f;
    s8 st;

    animate_object(obj);
    f = *(s8*)(obj + 0x45);
    if (f & 0x80) {
        obj[0x45] &= 0x7F;
        p = func_800F9AE0_spawn(obj);
        if (p != 0) {
            d = g_Player;
            ang = ratan2(*(s16*)(d + 0xE) - *(s16*)(obj + 0xE),
                         *(s16*)(d + 0xA) - *(s16*)(obj + 0xA));
            *(s32*)(p + 0x20) = rcos(ang);
            *(s32*)(p + 0x24) = -rsin(ang);
        }
    } else if (f == 1) {
        st = *(s8*)(obj + 2);
        if (st == 5) {
            set_animation(obj, 3);
        } else if (st == 6) {
            set_animation(obj, 4);
        } else if (st == 7) {
            set_animation(obj, 5);
        } else if (st == 8) {
            set_animation(obj, 6);
        }
        e = g_playthrough_state.u;
        e[0x28] &= obj[0x95];
        e[0x29] &= obj[0x96];
        obj[5]--;
    }
    func_8002D9EC(obj, 0x10, 0x10);
}

extern u8 D_80102A94_ovl04[];
extern u8 D_80102A98_ovl04[];

void func_800F9C68_ovl04(u8* obj) {
    u8* g = g_playthrough_state.u;
    s32 t;
    s8 k;

    g[0x28] &= ~obj[0x93];
    g[0x29] &= ~obj[0x93];
    t = *(s32*)(obj + 0x84) + 1;
    *(s32*)(obj + 0x84) = t;
    if (t >= 0x78) {
        k = obj[2];
        if (k == 5) {
            set_animation(obj, 3);
        } else if (k == 6) {
            set_animation(obj, 4);
        } else if (k == 7) {
            set_animation(obj, 5);
        } else if (k == 8) {
            set_animation(obj, 6);
        }
        obj[0x5C] = 0x10;
        *(u8**)(obj + 0x54) = D_80102A94_ovl04;
        *(u8**)(obj + 0x50) = D_80102A98_ovl04;
        obj[5] = 2;
        return;
    }
    if (t >= 0x3C) {
        if (t & 1) {
            k = obj[2];
            if (k == 5) {
                set_animation(obj, 3);
            } else if (k == 6) {
                set_animation(obj, 4);
            } else if (k == 7) {
                set_animation(obj, 5);
            } else if (k == 8) {
                set_animation(obj, 6);
            }
        } else {
            k = obj[2];
            if (k == 5) {
                set_animation(obj, 8);
            } else if (k == 6) {
                set_animation(obj, 0x34);
            } else if (k == 7) {
                set_animation(obj, 0x35);
            } else if (k == 8) {
                set_animation(obj, 0x36);
            }
        }
        obj[3] = 1;
        return;
    }
    if (t & 1) {
        obj[3] = 0;
        return;
    }
    obj[3] = 1;
}
