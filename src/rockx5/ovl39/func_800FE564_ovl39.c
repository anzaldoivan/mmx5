#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800FE564_ovl39(u8* obj) {
    u8* p;

    p = *(u8**)(obj + 0x50);
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    switch (p[0x47]) {
    case 0:
        obj[3] = 1;
        if (*(s8*)(obj + 0x5C) != p[0x47]) {
            set_animation(obj, 1);
        }
        obj[0x5C] = p[0x47];
        break;
    case 6:
    case 0xB ... 0x11:
        obj[3] = 1;
        if (*(s8*)(p + 0x45) == 8) {
            set_animation(obj, 5);
        }
        break;
    default:
        obj[3] = 0;
        break;
    }
    obj[0x5C] = p[0x47];
    animate_object(obj);
    if (*(s8*)(p + 4) == 2) {
        obj[4]++;
    }
}
