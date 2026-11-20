#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C01;
extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F2C1C_ovl20(u8* a0) {
    if (D_800D1C01 == 6) {
        set_animation_frame(a0, 0, 1);
    } else {
        set_animation_frame(a0, 0, 0);
    }
    func_8002D9EC(a0, 0x80, 0x80);
}
