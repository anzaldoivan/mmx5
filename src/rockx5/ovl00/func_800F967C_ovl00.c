#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F967C_ovl00(u8* obj) {
    if (!(--*(s16*)(obj + 0x7C) & 1)) {
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    }
    if (*(s8*)(obj + 7) == 3) {
        *(s16*)(obj + 0x7C) = 0x78;
        *(s16*)(obj + 0xE) = 0x11C;
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
