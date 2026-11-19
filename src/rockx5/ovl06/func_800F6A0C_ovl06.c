#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

extern s32 func_8002D800(u8* a0);

void func_800F6A0C_ovl06(u8* obj) {
    *(u16*)(obj + 0x42) &= 0x7FFF;
    if (func_8002D800(obj) == 0) {
        apply_object_motion(obj);
        obj[3] ^= 1;
        if (obj[3] != 0) {
            func_8002D89C(obj);
        }
    } else {
        clear_object_slot(obj);
    }
}
