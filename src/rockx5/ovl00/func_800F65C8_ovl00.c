#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void start_pad_vibration(s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern s16 D_8009A0AE;
extern u8 D_8009A244;
extern u8 D_800FB3B4_ovl00[];

void func_800F65C8_ovl00(u8* arg0) {
    s8 state;

    state = ((s8*)arg0)[2];
    switch (state) {
    case 0:
        if (D_8009A0AE < 0x3AA) {
            arg0[6] = 1;
            play_sound(5, 3, 0);
            play_sound(5, 4, 0);
            func_8002A5C4(0x10, 8, 1);
            *(s32*)(arg0 + 0x20) = -0x8000;
            func_80028B18(0, 0x10F0, 0x3C0, D_800FB3B4_ovl00);
            D_8009A244 = 1;
            start_pad_vibration(2);
        }
        break;
    case 1:
        if (D_8009A0AE < 0x260) {
            arg0[6] = state;
            play_sound(5, 3, 0);
            play_sound(5, 4, 0);
            func_8002A5C4(0x10, 8, 1);
            *(s32*)(arg0 + 0x20) = -0x8000;
            start_pad_vibration(2);
        }
        break;
    case 2:
    case 0x7E:
        if (D_8009A0AE < 0x2F0) {
            arg0[6] = 1;
            play_sound(5, 3, 0);
            play_sound(5, 4, 0);
            if (((s8*)arg0)[2] == 2) {
                func_8002A5C4(0x10, 8, 1);
            }
            *(s32*)(arg0 + 0x20) = 0x8000;
            start_pad_vibration(2);
        }
        break;
    }
}
