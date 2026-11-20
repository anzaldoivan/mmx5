#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1C00[];
extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F3EA0_ovl20(u8* a0) {
    s8* p = (s8*)D_800D1C00;
    s8 mode = p[0x30];

    if (mode == 4) {
        set_animation_frame(a0, 5, p[0x31]);
    } else if (mode == 2) {
        set_animation_frame(a0, 5, p[0x31] + 5);
    } else {
        set_animation_frame(a0, 5, 8);
    }
    func_8002D89C(a0);
}
