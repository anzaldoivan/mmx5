#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F085C_ovl08(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) == 2) {
        obj[0x8B] = 1;
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        *(s16*)(obj + 0x7C) = 4;
        *(s16*)(obj + 0x7E) = 0x1E;
        obj[0x6] = 1;
    }
}

extern s8 func_8002E024(Obj08B4*, u8*);

void func_800F08B4_ovl08(Obj08B4* obj) {
    animate_object(obj);
    if (--obj->timer != 0) {
        return;
    }
    if (obj->flip == 0) {
        obj->x -= 6;
    } else {
        obj->x += 6;
    }
    obj->hit = func_8002E024(obj, g_Player);
    if (obj->flip == 0) {
        obj->x += 6;
    } else {
        obj->x -= 6;
    }
    obj->state = 2;
}

void func_800F0964_ovl08(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (obj[2] & 0x10) {
            set_animation(obj, 0xC);
        } else {
            set_animation(obj, 6);
        }
        obj[6] = 4;
    }
}

void func_800F09D8_ovl08(u8* obj) {
    animate_object(obj);
    if ((s8)obj[0x45] == 2) {
        obj[0x8B] = 0;
    }
    if ((s8)obj[0x45] == 1) {
        if (obj[2] & 0x10) {
            set_animation(obj, 0);
        } else {
            set_animation(obj, 1);
        }
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 5;
    }
}

void func_800F0A5C_ovl08(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (obj[2] & 0x10) {
            set_animation(obj, 0);
        } else {
            set_animation(obj, 1);
        }
        if (obj[0x80] == 0) {
            *(s32*)(obj + 0x8C) = 0xB4;
            if (obj[0x15] == 0) {
                *(s32*)(obj + 0x20) = -0x18000;
            } else {
                *(s32*)(obj + 0x20) = 0x18000;
            }
            obj[5] = 2;
        } else {
            obj[0x88] = 0;
            obj[0x89] = 0x14;
            *(s32*)(obj + 0x8C) = 0x12C;
            obj[5] = 6;
        }
        obj[6] = 0;
    }
}
