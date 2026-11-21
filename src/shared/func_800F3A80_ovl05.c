#include "types.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 func_8002D800(u8* a0);

void func_800F3A80_ovl05(u8* obj) {
    if (func_8002D800(obj) == 0) {
        apply_object_motion(obj);
        animate_object(obj);
        obj[3] ^= 1;
        if (obj[3] != 0) {
            func_8002D89C(obj);
        }
    } else {
        clear_object_slot(obj);
    }
}
