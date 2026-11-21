#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define func_800F7244_ovl28 func_800FE520_ovl39
#include "shared/func_800F7244_ovl28.c"
#undef func_800F7244_ovl28

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

void func_800FE680_ovl39(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    animate_object(obj);
    if (*(s8*)(parent + 6) >= 3 || *(s8*)(parent + 4) == 2) {
        obj[4]++;
    }
}

extern u16 D_800FED48_ovl39[];

void func_800FE6E8_ovl39(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    *(u16*)(obj + 0xA) =
        *(u16*)(parent + 0xA) + D_800FED48_ovl39[*(s8*)(obj + 2) - 3];
    *(u16*)(obj + 0xE) = *(u16*)(parent + 0xE) + 0x70;
    animate_object(obj);
    if (*(s8*)(parent + 6) >= 10 || *(s8*)(parent + 4) == 2) {
        obj[4]++;
    }
}

void func_800FE788_ovl39(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    animate_object(obj);
    if (*(s8*)(obj + 0x5C) != 0) {
        obj[0x5C]--;
    } else {
        obj[4]++;
    }
    if (*(s8*)(parent + 4) == 2) {
        obj[4]++;
    }
}
