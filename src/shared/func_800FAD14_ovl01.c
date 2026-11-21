#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern s8 D_800D1C0C;
extern u8 D_800FD608_ovl01[];

void func_800FAD14_ovl01(u8* arg0) {
    s32 lim;

    lim = 0x40;
    if (D_800D1C0C != 0xC) {
        lim = 0x120;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    if (lim < *(s16*)(arg0 + 0xE)) {
        *(u8**)(arg0 + 0x68) = D_800FD608_ovl01;
    }
    if (arg0[0x70] & 8) {
        start_pad_vibration(5);
        arg0[0x15] = 0;
        set_animation(arg0, 0x10);
        play_sound(2, 7, arg0);
        func_8002A600(0x1E, 4, 2);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x2C) = 0;
        arg0[6] = 4;
    }
}
