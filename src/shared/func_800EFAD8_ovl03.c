#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern s8 D_800D1C26;

void func_800EFAD8_ovl03(Obj* arg0) {
    if (D_800D1C26 != 0) {
        arg0->timer = 0x1E;
        arg0->step++;
        play_sound(2, 0xE, arg0);
    }
}

extern u8 D_800F959C_ovl03[];
extern u8 D_800F95A4_ovl03[];

void func_800EFB20_ovl03(u8* arg0) {
    s32 t = *(u16*)(arg0 + 0x7C) - 1;

    *(u16*)(arg0 + 0x7C) = t;
    if ((s16)t == 0) {
        *(u8**)(arg0 + 0x54) = D_800F959C_ovl03;
        *(u8**)(arg0 + 0x50) = D_800F95A4_ovl03;
        arg0[6] = 0;
        arg0[5] = arg0[7];
    } else if (t & 1) {
        func_8002D9EC(arg0, 0x20, 0x20);
    } else {
        arg0[3] = 0;
    }
}
