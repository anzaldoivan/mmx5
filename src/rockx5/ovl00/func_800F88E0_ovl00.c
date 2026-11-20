#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F88E0_ovl00(Obj88E0* obj) {
    if (obj->flag46 == 0) {
        obj->unk28 = 0x2000;
        obj->timer = 0;
        obj->state++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
