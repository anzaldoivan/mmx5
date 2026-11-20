#include "types.h"
#include "mmx5/movement.h"

void func_800F5E14_ovl26(u8* obj) {
    if (*(s16*)(obj + 0x90) != 0) {
        (*(s16*)(obj + 0x90))--;
        return;
    }
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
    }
}
