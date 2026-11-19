#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F9200_ovl00(Obj8B54* obj) {
    if (obj->flag46 == 0) {
        obj->timer = 1;
        obj->count = 0;
        obj->state++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
