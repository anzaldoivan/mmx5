#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s8 D_8009A0A5;
extern s16 D_80102FD4_ovl04;
extern u8 D_800D1F20[];
extern u8 D_8009A296;

void func_800F012C_ovl04(u8* a0) {
    if (D_8009A0A5 == 0x14) {
        play_sound(5, 10, 0);
        a0[0x1C] = 0;
        D_80102FD4_ovl04 = 0x100;
        a0[6]++;
        D_800D1F20[2] = 7;
        D_8009A296 = 8;
    } else if (D_8009A0A5 == 2) {
        func_8003D29C(0x14, 0x40);
    }
}

#define func_800EFD54_ovl04 func_800F01B8_ovl04
#include "shared/func_800EFD54_ovl04.c"
#undef func_800EFD54_ovl04

void func_800F01F8_ovl04(u8* obj) {
    u8* g = g_playthrough_state.u;
    u8* b;

    if (g[0x26] & 4) {
        obj[6]++;
        b = D_8009A1F8.u;
        ((s8*)b)[0xA6] = -1;
        *(s16*)(b + 0x5E) = 0;
        *(s16*)(b + 0x62) = 0;
        b[0xA0] = 1;
        g[0x26] |= 8;
    }
}

void func_800F0254_ovl04(u8* a0) {
    a0[4] = 2;
}
