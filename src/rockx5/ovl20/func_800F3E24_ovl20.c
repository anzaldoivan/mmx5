#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1C00[];
extern s32 D_800F51F0_ovl20[];
extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F3E24_ovl20(u8* a0) {
    u8* p = D_800D1C00;

    set_animation_frame(a0, 1, ((s8*)p)[0x32]);
    if (D_800F51F0_ovl20[((s8*)p)[0x32]] & *(s32*)(p + 0x84)) {
        func_8002D89C(a0);
    } else {
        a0[3] = 0;
    }
}
