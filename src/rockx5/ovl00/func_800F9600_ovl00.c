#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F9600_ovl00(u8* obj) {
    if (*(s8*)(obj + 0x7) == 1) {
        obj[0x6]++;
    }
    if (!(--*(u16*)(obj + 0x7C) & 1)) {
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    }
    animate_object(obj);
    apply_object_motion(obj);
}
