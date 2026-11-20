/* Shared body (DK-5), from the banked draft of func_800F660C_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern u8 D_80074DA0[];
extern u8 D_800FBF38_ovl10[];
extern signed char D_800D1C0C;

void DEDUP_NAME(u8* o) {
    s32 y;
    s32 v;

    o[4] = 5;
    o[3] = 1;
    o[0x16] = 6;
    *(s32*)(o + 0x68) = 0;
    *(u8**)(o + 0x58) = D_80074DA0;
    *(u8**)(o + 0x54) = D_800FBF38_ovl10;
    *(u8**)(o + 0x50) = D_800FBF38_ovl10;
    *(s16*)(o + 0x88) = 0xAA;
    o[0x5C] = 0x18;
    o[0x60] = 4;
    set_animation(o, 5);
    if (D_800D1C0C != 12) {
        y = *(s16*)(o + 0xA);
        if (y < 0x1F61) {
            *(s16*)(o + 0x88) = 0x32;
            *(s32*)(o + 0x68) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x50) = 0;
            set_animation(o, 0x1B);
            v = 0x1F70;
            *(s16*)(o + 0xA) = v;
        } else if (y >= 0x20A0) {
            *(s16*)(o + 0x88) = 0x32;
            *(s32*)(o + 0x68) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x50) = 0;
            set_animation(o, 0x1B);
            v = 0x2090;
            *(s16*)(o + 0xA) = v;
        }
    } else {
        y = *(s16*)(o + 0xA);
        if (y < 0xA61) {
            *(s16*)(o + 0x88) = 0x32;
            *(s32*)(o + 0x68) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x50) = 0;
            set_animation(o, 0x1B);
            v = 0xA70;
            *(s16*)(o + 0xA) = v;
        } else if (y >= 0xBA0) {
            *(s16*)(o + 0x88) = 0x32;
            *(s32*)(o + 0x68) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x50) = 0;
            set_animation(o, 0x1B);
            v = 0xB90;
            *(s16*)(o + 0xA) = v;
        }
    }
    play_sound(2, 0x2D, o);
}
