#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern int func_80045D44();
extern u8 D_80076E60[];
extern u8 D_80076E64[];
extern u8 D_80076E68[];
extern u8 D_80076E6C[];
extern u8 D_8007B49C[];

void func_80045660(u8* obj) {
    u8* src;
    u8* p;
    u8* q;

    obj[0] = 1;
    *(u8**)(obj + 0x30) = D_8007B49C;
    obj[3] = 1;
    obj[0x16] = 1;
    src = *(u8**)(obj + 0x7C);
    if (*(s8*)(obj + 1) == 0x2D) {
        obj[0x15] = src[0x15];
        func_80045D44(obj, src, 0x2D);
        *(u8**)(obj + 0x68) = D_80076E64;
        *(u8**)(obj + 0x50) = D_80076E60;
        *(s16*)(obj + 0x40) = 0x520;
        p = D_1F80001C.bytes;
        p += *(s32*)(p + 0x1C);
        *(s32*)(obj + 0x20) = 0x6C000;
        *(s16*)(obj + 0x8E) = 0x20;
        *(s16*)(obj + 0x90) = 0x20;
        *(s16*)(obj + 0x92) = 0x50;
        *(s16*)(obj + 0x42) = 0x7842;
        *(u8**)(obj + 0x3C) = p;
        player_spawn_visual(0x21, 2, 0, 0);
    } else {
        *(u8**)(obj + 0x68) = D_80076E6C;
        *(u8**)(obj + 0x50) = D_80076E68;
        *(s16*)(obj + 0x40) = 0x540;
        q = D_1F80001C.bytes;
        q += *(s32*)(q + 0x18);
        *(s32*)(obj + 0x20) = 0xA0000;
        *(s16*)(obj + 0x8E) = 0x40;
        *(s16*)(obj + 0x90) = 0x40;
        *(s16*)(obj + 0x92) = 0x70;
        *(s16*)(obj + 0x42) = 0x7844;
        *(u8**)(obj + 0x3C) = q;
    }
    *(s16*)(obj + 0x8C) = *(s16*)(obj + 0xA);
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    set_animation(obj, 0);
    obj[4]++;
}

extern void func_80044F78(void* arg0);

void func_800457DC(u8* arg0) {
    s32 d;
    s32 lim;
    u8* g;

    if (is_off_screen(arg0, *(s16*)(arg0 + 0x8E), *(s16*)(arg0 + 0x90)) == 0) {
        animate_object(arg0);
        if (*(s8*)(arg0 + 0x98) == 0) {
            move_object(arg0);
            if (arg0[0x70] != 0 ||
                (((s32(*)())func_8002F8FC)(arg0), arg0[0x70] != 0)) {
                func_80044F78(arg0);
            } else {
                lim = *(s16*)(arg0 + 0x92);
                d = *(s16*)(arg0 + 0x8C) - *(s16*)(arg0 + 0xA);
                if ((d >= 0)
                        ? (lim < d)
                        : (lim < *(s16*)(arg0 + 0xA) - *(s16*)(arg0 + 0x8C))) {
                    g = g_Player;
                    arg0[3] = 0;
                    arg0[4] = 3;
                    *(s32*)(arg0 + 0x50) = 0;
                    *(s32*)(arg0 + 0x68) = 0;
                    g[0x98]--;
                    arg0[4] = 2;
                    if (*(s8*)(arg0 + 1) == 0x2D) {
                        set_animation(arg0, 1);
                    } else {
                        set_animation(arg0, 2);
                    }
                }
                func_8002D9EC(arg0, *(s16*)(arg0 + 0x8E), *(s16*)(arg0 + 0x90));
                return;
            }
        }
    }
    arg0[3] = 0;
    arg0[4] = 3;
    *(s32*)(arg0 + 0x50) = 0;
    *(s32*)(arg0 + 0x68) = 0;
}
