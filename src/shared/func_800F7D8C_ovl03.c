#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F7D8C_ovl03(Obj7D8C* obj) {
    if (++obj->timer == 20) {
        if (obj->kind == 2) {
            obj->vel = 0x30000;
        } else {
            obj->vel = -0x30000;
        }
        obj->timer = 1;
        obj->step++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
