#include "types.h"
#include "mmx5/movement.h"

void func_800F51C0_ovl10(u8* obj) {
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[0x61] = 0;
        obj[0x6] = 3;
    }
}
