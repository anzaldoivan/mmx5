#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2C30_ovl11(u8* obj) {
    s32 v;

    animate_object(obj);
    ((s32(*)())apply_object_motion)(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        D_1F80004C.bytes[0x80] = 4;
        set_animation(obj, 9);
        v = 3;
        obj[5] = v;
        v = 0x4200;
        *(s32*)(obj + 0x2C) = v;
        v = -1;
        obj[6] = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = v;
    }
}
