#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u16 D_800FA05E_ovl11;

void func_800F5DF4_ovl11(u8* arg0) {
    s16 dist;
    u16 x;
    u16 y;

    move_object(arg0);
    animate_object(arg0);
    dist = *(u16*)(arg0 + 0xE) - D_8009A1F8.bg[*(s8*)(arg0 + 0x14)].y_pos.i.hi;
    func_8002D9EC(arg0, 0x40, 0x40);
    if (*(s8*)(arg0 + 3) == 0) {
        arg0[0x9A] = 0;
    } else {
        arg0[0x9A] = 1;
    }
    arg0[3] = 1;
    if (dist >= 0x171) {
        arg0[0x9A] = 0;
        arg0[3] = 0;
        *(s32*)(arg0 + 0x54) = 0;
        *(s32*)(arg0 + 0x50) = 0;
        D_1F80004C.bytes[0x92] = 3;
        if (*(s16*)(arg0 + 0x7E) == 0) {
            set_animation(arg0, 1);
            x = D_8009A0AA;
            y = D_800FA05E_ovl11 + 0x60;
            *(u16*)(arg0 + 0xA) = x;
            *(u16*)(arg0 + 0xE) = y;
            *(s16*)(arg0 + 0x7C) =
                (0x140 - (u8)(((u32(*)())random_byte)() % 3) * 0x10) / 4;
            *(s32*)(arg0 + 0x20) = 0;
            *(s32*)(arg0 + 0x24) = 0x40000;
            arg0[6] = 9;
            D_1F80004C.bytes[0x93] = 0x1E;
            return;
        }
        arg0[6] = 2;
        *(s16*)(arg0 + 0x7C) = 0x1E;
    }
}
