#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9C30_ovl28(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 2);
        obj[5] = 3;
        obj[6] = 0;
    }
    func_8002D9EC(obj, 0x30, 0x30);
    animate_object(obj);
    apply_object_motion(obj);
}
