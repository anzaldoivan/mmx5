#include "types.h"
#include "mmx5/object.h"

extern s32 D_8009A1F8[][21];

void func_800F4434_ovl06(u8* a0) {
    s32 d;

    move_object(a0);
    d = *(s32*)(a0 + 8) - D_8009A1F8[((s8*)a0)[0x14]][2];
    if (d > 0x300000 && d < 0x1100000) {
        a0[5] = 1;
    }
}
