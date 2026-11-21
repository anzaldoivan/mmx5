#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F5950_ovl27(Obj5820* arg0) {
    if (--arg0->unk7C == 0) {
        arg0->unk7C = 0x28;
        if (--arg0->unk7E != -1) {
            func_800F5B44_ovl27(arg0, 1);
            play_sound(2, 0x5D, arg0);
        } else {
            arg0->unk5 = 2;
            arg0->unk6 = 0;
        }
    }
}

#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F59D8_ovl27(X4_Obj* arg0) {
    s16 off;
    s16 x;
    s32 t;
    u8 v;

    D_1F80004C.bytes[0x86]++;
    off = arg0->y_pos.u.hi - (g_Player_as_X4_Obj.y_pos.u.hi - 0x19);
    if (arg0->unk15 == 0) {
        t = off - 0x2C;
        x = arg0->x_pos.i.hi + t;
    } else {
        t = off - 0x2C;
        x = arg0->x_pos.i.hi - t;
    }
    if (ABS(g_Player_as_X4_Obj.x_pos.i.hi - x) < 0x21) {
        v = 5;
    } else {
        v = 4;
    }
    arg0->unk5 = v;
    arg0->unk6 = 0;
}
