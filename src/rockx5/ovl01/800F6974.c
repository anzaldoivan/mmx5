#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6974_ovl01(u8* obj) {
    animate_object(obj);
    if (D_8009A0AA < *(s16*)(obj + 0xA) + 8 && *(signed char*)(obj + 3) != 0) {
        *(s16*)(obj + 0x7C) = 0x78;
        set_animation(obj, 5);
        obj[6]++;
    }
}

extern void func_800F6D48_ovl01(u8* obj);

void func_800F69E4_ovl01(u8* obj) {
    if (*(signed char*)(obj + 0x45) != 0) {
        func_800F6D48_ovl01(obj);
        obj[6]++;
        set_animation(obj, 4);
    } else {
        *(u16*)(obj + 0x7C) -= 1;
        animate_object(obj);
    }
}

void func_800F6A50_ovl01(u8* obj) {
    if (*(signed char*)(obj + 0x45) != 0) {
        set_animation(obj, 3);
        obj[6]++;
    } else {
        *(u16*)(obj + 0x7C) -= 1;
        animate_object(obj);
    }
}

#include "shared/func_800F6AB0_ovl01.c"

#define D_800EEC60_ovl00 func_800F6AF4_ovl01
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
