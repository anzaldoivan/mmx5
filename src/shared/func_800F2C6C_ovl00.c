#include "types.h"
#include "mmx5/movement.h"

void func_800F2C6C_ovl00(Obj2C6C* obj) {
    if (obj->flags70 & 8) {
        obj->unk24 = 0;
        obj->unk2C = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk67 = 0;
        obj->state++;
    } else {
        apply_object_motion(obj);
    }
}
