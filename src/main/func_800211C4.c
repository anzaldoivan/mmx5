#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#define D_800C931C_as_Pad800218E0 (*(Pad800218E0*)&g_pad1_buttons)

void func_800211C4(signed char* p, s32 lim) {
    if (D_800C931C_as_Pad800218E0.unk4 & 0x1000) {
        play_sound(0, 0xC, 0);
        if (*p == 0) {
            *p = lim;
        } else {
            (*p)--;
        }
    }
    if (D_800C931C_as_Pad800218E0.unk4 & 0x4000) {
        play_sound(0, 0xC, 0);
        if (*p == lim) {
            *p = 0;
        } else {
            (*p)++;
        }
    }
}
