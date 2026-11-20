#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800D1C00[];

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
        e = D_800D1C00;
        e[0x28] &= obj[0x95];
        e[0x29] &= obj[0x96];
        obj[5]--;
    }
    func_8002D9EC(obj, 0x10, 0x10);
}
