#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F8B54_ovl00(Obj8B54* obj) {
    if (obj->flag46 == 0) {
        set_animation(obj, 1);
        obj->timer = 10;
        obj->count = 0;
        obj->state++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
