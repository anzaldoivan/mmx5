#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F1608_ovl28(u8* obj) {
    s32 v;

    animate_object(obj);
    ((s32(*)())apply_object_motion)(obj);
    v = *(s32*)(obj + 0x24);
    if (v == 0) {
        *(s16*)(obj + 0x7C) = 0x28;
        *(s32*)(obj + 0x24) = v;
        *(s32*)(obj + 0x2C) = -0x1000;
        obj[6]++;
    }
}
