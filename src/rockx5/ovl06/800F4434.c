#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern s32 D_8009A1F8[][21];

void func_800F4434_ovl06(u8* a0) {
    s32 d;

    move_object(a0);
    d = *(s32*)(a0 + 8) - D_8009A1F8[((s8*)a0)[0x14]][2];
    if (d > 0x300000 && d < 0x1100000) {
        a0[5] = 1;
    }
}

extern s16 D_8009A202;

void func_800F44AC_ovl06(u8* obj) {
    if (*(s8*)(obj + 0x45) == 7) {
        set_animation(obj, 0);
    }
    obj[0x89]++;
    obj[0x89] %= 120;
    move_object(obj);
    if (*(s16*)(obj + 0xA) - D_8009A202 >= 0x51) {
        *(s32*)(obj + 8) = *(s32*)(obj + 0x18);
    }
}
