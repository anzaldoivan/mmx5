#include "types.h"
#include "mmx5/graphics.h"

void func_800EF970_ovl18(u8* obj) {
    s8 state = ((s8*)obj)[2];

    if (state == 0) {
        if (((s8*)*(u8**)(obj + 0x50))[2] == 10) {
            set_animation(obj, 7);
        } else {
            set_animation(obj, 0);
        }
        obj[5] = 0;
    } else if (state == 1) {
        set_animation(obj, 2);
        obj[5] = 3;
    } else if (state == 2) {
        if (((s8*)*(u8**)(obj + 0x50))[2] == 10) {
            set_animation(obj, 8);
        } else {
            set_animation(obj, 1);
        }
        obj[5] = 0;
    } else if (state == 3) {
        set_animation(obj, 6);
        obj[5] = 3;
    }
    obj[4]++;
}
