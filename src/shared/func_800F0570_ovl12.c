#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F0570_ovl12(Ent* obj) {
    set_animation(obj, 5);
    if (D_8009A0AA > obj->y) {
        obj->flag15 = 0x40;
    } else {
        obj->flag15 = 0;
    }
    obj->state++;
    animate_object(obj);
    apply_object_motion(obj);
}
