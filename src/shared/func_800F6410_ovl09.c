#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6410_ovl09(u8* obj) {
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 20;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F646C_ovl09(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0);
        *(s32*)(obj + 0x24) = 0x30000;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FB61E_ovl09;

void func_800F64D4_ovl09(u8* obj) {
    if (*(s16*)(obj + 0xE) <= D_800FB61E_ovl09) {
        obj[0x94] = 0x3C;
        *(s16*)(obj + 0xE) = D_800FB61E_ovl09;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[0x5] = 4;
        obj[0x6] = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
