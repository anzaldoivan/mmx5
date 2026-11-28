#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void start_pad_vibration(s32);
extern void silence_sound(s32, s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern u8 D_8009A244;
extern u8 D_800F9BB8_ovl11[];
extern u8 D_800F9BC0_ovl11[];
extern u8 D_800F9BC8_ovl11[];

void func_800F36E8_ovl11(u8* a0) {
    u8* g;
    u8* h;
    u8 t;

    g = g_Player;
    if (((s8*)g)[0xF3] == 0) {
        move_object(a0);
    } else if ((u32)(g[0xFA] - 2) >= 2U) {
        move_object(a0);
    }
    if (*(s16*)(a0 + 0xE) == 0x490 && a0[0x82] == 0) {
        start_pad_vibration(3);
        ((s32(*)())func_80028B18)(0, 0x800, 0x4B0, D_800F9BB8_ovl11);
        D_8009A244 = 1;
        a0[7] = 3;
        a0[0x82]++;
    } else if (*(s16*)(a0 + 0xE) == 0x580 && (t = a0[0x82]) == 1) {
        start_pad_vibration(3);
        ((s32(*)())func_80028B18)(0, 0x7A0, 0x5A0, D_800F9BC0_ovl11);
        a0[7] = 4;
        D_8009A244 = 1;
        a0[0x82]++;
    } else if (*(s16*)(a0 + 0xE) == 0x670 && a0[0x82] == 2) {
        start_pad_vibration(3);
        ((s32(*)())func_80028B18)(0, 0x800, 0x690, D_800F9BC8_ovl11);
        a0[7] = 5;
        D_8009A244 = 1;
    }
    h = g_Player;
    if (*(s16*)(h + 0xA) >= 0x930 && g_playthrough_state.s[0x29] == 0) {
        silence_sound(5, 0x1D);
        g_playthrough_state.s[0x29] = 1;
    }
    if (*(s16*)(a0 + 0xE) >= 0x850) {
        a0[5] = 8;
        if (g_playthrough_state.s[0x1D] < 2) {
            if (g_playthrough_state.s[0x29] == 0) {
                silence_sound(5, 0x1D);
                g_playthrough_state.s[0x29] = 1;
            }
            play_sound(5, 0x1B, a0);
            func_8002A5C4(0x20, 4, 1);
        }
    }
}
