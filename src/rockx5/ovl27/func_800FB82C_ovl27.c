#include "types.h"
#include "mmx5/graphics.h"

void func_800FB82C_ovl27(u8* obj) {
    switch (((s8*)obj)[2]) {
    case 0:
        set_animation(obj, 0x15);
        obj[0x16] = 4;
        break;
    case 1:
        set_animation(obj, 0x17);
        obj[0x16] = 4;
        break;
    case 2:
        set_animation(obj, 0x16);
        obj[0x16] = 4;
        break;
    case 3:
        set_animation(obj, 0x15);
        obj[0x16] = 4;
        break;
    case 4:
        set_animation(obj, 0x1A);
        obj[0x16] = 5;
        break;
    case 5:
        set_animation(obj, 0x1C);
        obj[0x16] = 5;
        break;
    case 6:
        set_animation(obj, 0x1B);
        obj[0x16] = 5;
        break;
    }
    obj[3] = 1;
    *(s16*)(obj + 0x54) = 0x78;
    obj[5] = 0;
    obj[6] = 0;
    obj[4]++;
}
