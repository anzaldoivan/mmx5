#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void func_80044F78(void* arg0);
extern s32 D_80077240[];
extern u8 D_80077254[];
extern u8 D_8007B3D8[];

void func_8004BCBC(u8* arg0) {
    u8* g = g_Player;
    u8* s;
    s32 v;
    s32 e;
    s32 h;
    s32 t;
    s8 st;

    st = FX(arg0, s8, 0x4);
    if (st == 0) {
        FX(arg0, u8, 0x3) = 1;
        FX(arg0, s32*, 0x68) = D_80077240;
        FX(arg0, u8*, 0x50) = D_80077254;
        s = D_1F80001C.bytes;
        FX(arg0, u8*, 0x3C) = s + FX(s, s32, 0x4);
        FX(arg0, u8*, 0x30) = D_8007B3D8;
        FX(arg0, s16, 0x40) = 0;
        FX(arg0, s16, 0x42) = 0x7802;
        FX(arg0, u8, 0x16) = 1;
        if (FX(arg0, u8, 0x15) == 0) {
            FX(arg0, s16, 0xA) = FX(g, s16, 0xA) - 0x14;
            if (FX(g, s32, 0xFC) & 0x200) {
                FX(arg0, s32, 0x20) = 0xFFF34000;
            } else {
                FX(arg0, s32, 0x20) = 0xFFF74000;
            }
        } else {
            FX(arg0, s16, 0xA) = FX(g, s16, 0xA) + 0x14;
            v = 0x80000;
            if (FX(g, s32, 0xFC) & 0x200) {
                v = 0xC0000;
            }
            FX(arg0, s32, 0x20) = v | 0xC000;
        }
        FX(arg0, s16, 0xE) = FX(g, s16, 0xE) - 0xA;
        FX(arg0, s32, 0x24) = 0;
        set_animation(arg0, 1);
        FX(arg0, s32, 0x84) = FX(arg0, s16, 0xA);
        FX(arg0, u8, 0x4)++;
    } else if (st == 1) {
        if (is_off_screen(arg0, 0x10, 0x10) != 0 || FX(arg0, s8, 0x98) != 0) {
            clear_object_slot(arg0);
            return;
        }
        FX(arg0, s32*, 0x68) = &D_80077240[FX(arg0, u8, 0x45) & 0x7F];
        if (FX(arg0, u8, 0x70) != 0 ||
            (((s32(*)())func_8002F8FC)(arg0), FX(arg0, u8, 0x70) != 0)) {
            func_80044F78(arg0);
            clear_object_slot(arg0);
            return;
        }
        animate_object(arg0);
        t = FX(arg0, u8, 0x45);
        FX(arg0, s32*, 0x68) = &D_80077240[t & 0x7F];
        if (t & 0x80) {
            move_object(arg0);
        } else if (FX(g, s8, 0x5) == 0x11) {
            clear_object_slot(arg0);
            return;
        }
        h = FX(arg0, s16, 0xA);
        e = FX(arg0, s32, 0x84);
        if (((e - h) < 0 ? (h - e) : (e - h)) >= 0xA0) {
            FX(arg0, u8, 0x4)++;
            set_animation(arg0, 0xC);
            FX(arg0, s32, 0x68) = 0;
            FX(arg0, s32, 0x50) = 0;
            return;
        }
    } else {
        animate_object(arg0);
        if (is_off_screen(arg0, 0x10, 0x10) != 0 || FX(arg0, s8, 0x46) == 0) {
            clear_object_slot(arg0);
            return;
        }
    }
    func_8002D9EC(arg0, 0x10, 0x10);
}
