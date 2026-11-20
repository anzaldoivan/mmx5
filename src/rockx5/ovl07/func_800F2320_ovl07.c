#include "types.h"
#include "mmx5/graphics.h"

void func_800F2320_ovl07(u8* obj) {
    s32 d;

    if (*(s8*)(obj + 0x2) != 0) {
        if (*(s16*)(obj + 0x7E) - *(s16*)(obj + 0xE) >= 0) {
            d = obj[0x7E] - obj[0xE];
        } else {
            d = obj[0xE] - obj[0x7E];
        }
        obj[0x82] = d;
        switch (obj[0x82]) {
        case 0x0:
            set_animation(obj, 3);
            break;
        case 0x10:
            set_animation(obj, 2);
            break;
        case 0x20:
            set_animation(obj, 1);
            break;
        }
        *(s16*)(obj + 0xC) = 0;
    } else {
        if (*(s16*)(obj + 0x7C) - *(s16*)(obj + 0xA) >= 0) {
            d = obj[0x7C] - obj[0xA];
        } else {
            d = obj[0xA] - obj[0x7C];
        }
        obj[0x82] = d;
        switch (obj[0x82]) {
        case 0x0:
            set_animation(obj, 8);
            break;
        case 0x10:
            set_animation(obj, 7);
            break;
        case 0x20:
            set_animation(obj, 6);
            break;
        case 0x30:
            set_animation(obj, 5);
            break;
        }
        *(s16*)(obj + 0x8) = 0;
    }
    obj[0x6]++;
}
