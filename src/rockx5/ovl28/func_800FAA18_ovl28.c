#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FAA18_ovl28(ObjFA798* obj) {
    if (obj->f46 == 0) {
        obj->f4 = 2;
    }
    if (obj->parent->state == 2) {
        obj->f4 = 2;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    animate_object(obj);
    move_object(obj);
}
