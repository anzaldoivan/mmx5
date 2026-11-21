#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2AC0_ovl11(u8* obj) {
    animate_object(obj);
    ((s32(*)())apply_object_motion)(obj);
    if (obj[0x70] & 8) {
        if (D_1F80004C.bytes[0x80] == 4) {
            set_animation(obj, 0x17);
        } else {
            set_animation(obj, 0x18);
        }
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
    }
}

void func_800F2B50_ovl11(u8* obj) {
    s32 v;

    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        v = 2;
        if (D_1F80004C.bytes[0x85] == 2) {
            v = 7;
        }
        obj[5] = v;
        obj[6] = 0;
        obj[0x67] = 0;
    }
}
