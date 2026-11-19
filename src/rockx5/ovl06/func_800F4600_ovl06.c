#include "types.h"
#include "mmx5/graphics.h"

extern s16 D_8009A0AE;

void func_800F4600_ovl06(u8* obj) {
    if (*(s8*)(obj + 0x45) == 7) {
        set_animation(obj, 0);
    }
    if (*(s16*)(obj + 0xE) > D_8009A0AE) {
        *(s16*)(obj + 0xE) -= 1;
    } else if (*(s16*)(obj + 0xE) < D_8009A0AE) {
        *(s16*)(obj + 0xE) += 1;
    } else {
        obj[5] = 1;
    }
    if (++*(s16*)(obj + 0x7C) >= 0x3D) {
        obj[5] = 1;
    }
}
