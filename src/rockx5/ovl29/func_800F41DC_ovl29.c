#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F41DC_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 0x11);
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
