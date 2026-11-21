#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern s16 D_8009A202;
extern void (*D_800FE634_ovl06[])(u8*);

void func_800F458C_ovl06(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xA) - D_8009A202 >= 0x51) {
        *(s32*)(a0 + 0x8) = *(s32*)(a0 + 0x18);
    }
    D_800FE634_ovl06[*(s8*)(a0 + 0x6)](a0);
}

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
