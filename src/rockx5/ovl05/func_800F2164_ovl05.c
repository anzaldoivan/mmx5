#include "types.h"
#include "mmx5/graphics.h"

void func_800F2164_ovl05(u8* obj) {
    if (obj[0x90] != 0) {
        switch (*(signed char*)(obj + 2)) {
        case 0:
        case 1:
        case 2:
            set_animation(obj, 0x15);
            break;
        case 3:
        case 4:
        case 5:
            set_animation(obj, 8);
            break;
        }
        obj[6] = 4;
        *(s16*)(obj + 0x8A) = *(s16*)(obj + 0x88);
    } else if (--*(s16*)(obj + 0x88) == -1) {
        switch (*(signed char*)(obj + 2)) {
        case 0:
        case 1:
        case 2:
            set_animation(obj, 0x15);
            break;
        case 3:
        case 4:
        case 5:
            set_animation(obj, 8);
            break;
        }
        obj[6]++;
    }
    obj[0x8C] = 0;
    obj[0x8E] = obj[0x45];
}
