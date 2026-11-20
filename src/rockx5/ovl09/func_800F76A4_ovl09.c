#include "types.h"
#include "mmx5/graphics.h"

extern s8 D_8009A170;
extern s16 D_8009A1F8[];

void func_800F76A4_ovl09(u8* obj) {
    if (D_8009A170 < 0) {
        *(s16*)(obj + 0x84) = 0;
        D_8009A1F8[0x12] = D_8009A1F8[0x13] = D_8009A1F8[5];
        set_animation(obj, 1);
        obj[5] = 2;
    }
}
