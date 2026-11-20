#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2BD0_ovl01(u8* obj) {
    s32 vx;

    animate_object(obj);
    move_object(obj);
    if (--D_1F80004C.bytes[0x80] == 0xFF) {
        set_animation(obj, 3);
        obj[5] = 6;
        obj[6] = 0;
        vx = -0x20000;
        if (obj[0x15] != 0) {
            vx = 0x20000;
        }
        *(s32*)(obj + 0x20) = vx;
        *(s32*)(obj + 0x24) = 0x25000;
        *(s32*)(obj + 0x2C) = 0x1800;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 1;
    }
}
