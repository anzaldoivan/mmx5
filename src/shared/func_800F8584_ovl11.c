#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"

void func_800F8584_ovl11(u8* obj) {
    animate_object(obj);
    *(s32*)(obj + 0x24) = 0;
    obj[0x95] = 0;
    obj[6]++;
}

void func_800F85BC_ovl11(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (is_off_screen(obj, 0x40, 0x40) == 1) {
        obj[4] = 2;
    }
}
