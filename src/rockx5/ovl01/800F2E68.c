#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2E68_ovl01(u8* obj) {
    animate_object(obj);
    if (obj[0x70] & 8) {
        obj[6] = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 0;
        if (D_1F80004C.bytes[0x81] != 0) {
            set_animation(obj, 4);
            obj[6]++;
        } else {
            obj[5] = 2;
            obj[6] = 0;
        }
    } else {
        apply_object_motion(obj);
    }
}

void func_800F2F08_ovl01(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[5] = 3;
        obj[6] = 0;
    }
}
