#include "types.h"
#include "mmx5/graphics.h"

extern u8 D_8009A0B4;
extern s8 D_800D1C0C;

void func_800F47F4_ovl10(u8* obj) {
    obj[0x14] = D_8009A0B4;
    switch (*(s8*)(obj + 2)) {
    case 0:
        obj[0x16] = 5;
        set_animation(obj, 0x12);
        if (D_800D1C0C != 0xC) {
            *(s16*)(obj + 0xA) = 0x2060;
            *(s16*)(obj + 0xE) = 0x480;
        } else {
            *(s16*)(obj + 0xA) = 0xB60;
            *(s16*)(obj + 0xE) = 0xC0;
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x2C) = 0;
        break;
    case 1:
        obj[0x16] = 5;
        set_animation(obj, 0x16);
        *(s32*)(obj + 0x20) = 0xFFFF0000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x40000;
        *(s32*)(obj + 0x2C) = 0x5000;
        break;
    case 2:
        obj[0x16] = 5;
        set_animation(obj, 6);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        break;
    case 3:
        obj[0x16] = 7;
        set_animation(obj, 0x19);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[0x54] = 0;
        break;
    }
    obj[4] = 1;
}
