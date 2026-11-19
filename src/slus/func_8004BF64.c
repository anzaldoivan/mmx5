#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void set_velocity_from_angle(void*, s32);
extern void load_buffered_palette(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_8007723C[];
extern u8 D_800774F0[];
extern u8 D_8007B3D8[];

void func_8004BF64(u8* arg0) {
    u8* g = g_Player;
    u8* s;
    s32 n;

    if (FX(arg0, s8, 0x4) == 0) {
        FX(arg0, u8, 0x3) = 1;
        FX(arg0, u8*, 0x50) = D_8007723C;
        s = D_1F80001C.bytes;
        n = FX(s, s32, 0x18);
        FX(arg0, u8*, 0x30) = D_8007B3D8;
        FX(arg0, s16, 0x40) = 0;
        FX(arg0, s16, 0x42) = 0x7843;
        FX(arg0, u8, 0x16) = 1;
        FX(arg0, u8*, 0x3C) = s + n;
        load_buffered_palette(0x54, 0x13, 1, n);
        FX(arg0, s16, 0xA) = FX(g, s16, 0xA);
        FX(arg0, s16, 0xE) = FX(g, s16, 0xE) + 0x15;
        if (FX(arg0, s8, 0x2) >= 5) {
            FX(arg0, u8, 0x15) = 0x40;
        } else {
            FX(arg0, u8, 0x15) = 0;
        }
        set_velocity_from_angle(arg0, (0x10 - FX(arg0, s8, 0x2) * 2) & 0xFE);
        FX(arg0, s32, 0x20) = FX(arg0, s32, 0x20) * 7;
        FX(arg0, s32, 0x24) = FX(arg0, s32, 0x24) * 7;
        set_animation(arg0, D_800774F0[FX(arg0, s8, 0x2)]);
        move_object(arg0);
        move_object(arg0);
        move_object(arg0);
        FX(arg0, u8, 0x4)++;
    } else if (is_off_screen(arg0, 0x20, 0x20) == 0 &&
               FX(arg0, s8, 0x98) == 0) {
        animate_object(arg0);
        move_object(arg0);
    } else {
        clear_object_slot(arg0);
        return;
    }
    func_8002D89C(arg0, 0x20, 0x20);
}
