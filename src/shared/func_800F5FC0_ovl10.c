#include "types.h"
#include "mmx5/ovl10.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

void func_800F5FC0_ovl10(u8* obj) {
    set_animation(obj, 1);
    obj[6] = 1;
}

void func_800F5FF0_ovl10(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 0);
        *(s16*)(obj + 0x7C) = 0x78;
        obj[6] = 4;
    }
}

void func_800F603C_ovl10(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] =
            D_800FBE00_ovl10.u[++obj[0x88] + (obj[0x8A] * 2 + obj[0x89]) * 5];
        obj[6] = 0;
    }
}
