#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s8 D_800D1C2C;

void func_800F08D8_ovl20(u8* arg0) {
    u16 pad = D_800C9320.h;
    s8 v;
    u8* p;

    if (pad & 0x5000) {
        if (arg0[0x10F] != 2 && arg0[0x10F] != 4) {
            play_sound(5, 0, 0);
            p = g_playthrough_state.u;
            if ((s8)++p[0x2C] >= 2) {
                p[0x2C] = 0;
            }
        }
    } else if (pad & 0x840) {
        play_sound(5, 1, 0);
        v = D_800D1C2C;
        if (v != 0) {
            v = 9;
        } else {
            v = 8;
        }
        arg0[1] = v;
        goto tail; // !FAKE: goto kept for the matching branch layout
    } else if (pad & 4) {
        play_sound(5, 0, 0);
        pad = 10;
        goto store; // !FAKE: goto kept for the matching branch layout
    } else if (pad & 8) {
        play_sound(5, 0, 0);
        pad = 5;
    store: // !FAKE: label kept for the matching branch layout
        arg0[1] = pad;
    tail: // !FAKE: label kept for the matching branch layout
        arg0[2] = 0;
    }
}
