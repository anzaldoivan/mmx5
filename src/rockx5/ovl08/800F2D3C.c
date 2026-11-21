#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern u8 D_8009A198;

void func_800F2D3C_ovl08(u8* a0) {
    s8 state = ((s8*)a0)[6];
    s8 r;

    if (state == 0) {
        a0[6]++;
        return;
    }
    if (state == 1) {
        r = func_80031DD0(a0);
        if (r < 0) {
            a0[5] = state;
            a0[6] = 0;
            return;
        }
        if (r > 0) {
            *(u16*)(a0 + 0x42) |= 0x8000;
        } else {
            *(u16*)(a0 + 0x42) &= 0x7FFF;
        }
        ((void (*)())func_80033024)(a0);
        if (D_8009A198 == 0) {
            func_8003240C(a0);
        }
        func_8003258C(a0);
    }
}

#define D_8007BD4C D_800F3FEC_ovl08

#define func_800532E0 func_800F2DFC_ovl08
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

void func_800F2E38_ovl08(u8* obj) {
    *(u16*)(obj + 0x42) &= 0x7FFF;
    set_animation(obj, 1);
    obj[0x75] = 0;
    obj[6]++;
}

void func_800F2E7C_ovl08(u8* a0) {
    u8* p = g_Player;

    if (*(s16*)(p + 0xA) >= 0x196) {
        *(s16*)(p + 0xA) = 0x195;
    }
    if (*(s8*)(a0 + 0x45) == 1) {
        play_sound(5, 0x15, a0);
        a0[5] = 2;
        a0[6] = 0;
    }
}
