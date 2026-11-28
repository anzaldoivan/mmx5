#include "types.h"
#include "mmx5/graphics.h"

void func_80023260(u8* obj, u8* other) {
    s8 side = ((s8*)obj)[2];
    s32 want = (side == 0) ? 2 : 1;

    if (((s8*)other)[0x9B] == want || ((s8*)other)[0x9C] == want) {
        obj[3] = 1;
        set_animation(obj, side + 8);
        obj[4]++;
    }
}
