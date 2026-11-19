#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F94D0_ovl00(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        *(s16*)(obj + 0x7C) = 0x46;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
