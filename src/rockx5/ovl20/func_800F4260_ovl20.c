#include "types.h"
#include "mmx5/globals.h"

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);
extern s8 D_800D1C2A;

void func_800F4260_ovl20(u8* arg0) {
    set_animation_frame(arg0, 6, D_800D1C2A);
    func_8002D89C(arg0);
}
