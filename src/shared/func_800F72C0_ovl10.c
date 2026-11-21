#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

extern s8 D_8009A0A2;

void func_800F72C0_ovl10(Obj72C0* obj) {
    obj->b4 = 0xF;
    obj->b3 = 1;
    obj->b16 = 2;
    obj->w68 = 0;
    obj->w54 = 0;
    obj->w50 = 0;
    if (D_8009A0A2 != 0) {
        set_animation(obj, 0x1E);
    } else {
        set_animation(obj, 0x1C);
    }
    if (obj->parent->state == 3) {
        clear_object_slot(obj);
    }
}

void func_800F7354_ovl10(u8* obj) {
    *(u16*)(obj + 0x42) = *(u16*)(*(u8**)(obj + 0x7C) + 0x42);
    obj[0x15] = g_Player[0x15];
    if ((u8)(obj[0x47] + 0x56) < 2) {
        obj[0x16] = 5;
    } else {
        obj[0x16] = 2;
    }
    animate_object(obj);
    ((s32(*)())func_8002D89C)(obj);
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        s8* g = (s8*)g_Player;
        obj[4] = 0x10;
        if (g[2] != 0) {
            set_animation(obj, 0x1F);
        } else {
            set_animation(obj, 0x1D);
        }
    }
    if (g_Player[0x5C] == 0x80) {
        clear_object_slot(obj);
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 3) {
        clear_object_slot(obj);
    }
}

void func_800F7458_ovl10(u8* obj) {
    if (obj[0x47] == 0xAA || obj[0x47] == 0xAB) {
        obj[0x16] = 2;
    } else {
        obj[0x16] = 5;
    }
    animate_object(obj);
    func_8002D89C(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        clear_object_slot(obj);
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 3) {
        clear_object_slot(obj);
    }
}
