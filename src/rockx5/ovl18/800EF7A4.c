#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s32 func_800EF57C_ovl18(u8* obj, u8* base);

void func_800EF7A4_ovl18(u8* obj) {
    u8* p = g_Player;

    if (func_800EF57C_ovl18(obj, p) != 0) {
        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE) - (*(u8**)(p + 0x68))[3];
        ((s32(*)())func_8003D29C)(0x14, p[0x15]);
        obj[6]++;
    }
}

extern s8 D_8009A0A5;

void func_800EF818_ovl18(u8* arg0) {
    if (D_8009A0A5 == 0x14) {
        *(s16*)(arg0 + 0x7C) = 0x2A;
        arg0[6]++;
        play_sound(5, 0x16, arg0);
    }
}

extern u8 D_8009A0B5;

void func_800EF864_ovl18(u8* a0) {
    if (--*(s16*)(a0 + 0x7C) == 0) {
        ((s32(*)())func_8003D29C)(0x16, D_8009A0B5);
        *(s16*)(a0 + 0x7C) = 0x28;
        a0[6] = a0[6] + 1;
    }
}

extern s8 D_8009A170;
extern u8 D_800D1C00[];

void func_800EF8C0_ovl18(u8* p) {
    u8* d;
    u8 t;

    if (*(s16*)(p + 0x7C) == 0 || --*(s16*)(p + 0x7C) == 0) {
        if (D_8009A170 < 0) {
            func_8003D2C4();
            d = D_800D1C00;
            t = p[2];
            ((s8*)d)[0xF] = -0x40;
            d[0x1D] = t & 0xF;
            p[6]++;
        }
    }
}

#define D_800EEC60_ovl00 func_800EF948_ovl18
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
