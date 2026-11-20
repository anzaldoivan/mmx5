#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F563C_ovl29(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
        set_animation(obj, 0);
        if (obj[0x8A] & 1) {
            obj[0x8A] = 0x3D;
        } else {
            obj[0x8A] = 0x3E;
        }
        *(s16*)(obj + 0x7C) = 1;
    }
}
