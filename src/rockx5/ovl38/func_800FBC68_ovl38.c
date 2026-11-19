#include "types.h"
#include "mmx5/graphics.h"

extern s32 func_80044DE0();

void func_800FBC68_ovl38(u8* arg0) {
    if (func_80044DE0() == 0) {
        set_animation(arg0, 1);
        arg0[6]++;
    }
}
