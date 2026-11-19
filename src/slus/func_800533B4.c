#include "types.h"
#include "mmx5/graphics.h"

void func_800533B4(u8* obj) {
    s8 state = ((s8*)obj)[2];

    if (state == 1) {
        obj[6] = state;
        return;
    }
    set_animation(obj, 1);
    obj[6] = 2;
}
