#include "types.h"
#include "mmx5/globals.h"

void func_800F5168_ovl10(Obj5CF0* obj) {
    animate_object(obj);
    if (--obj->unk7C == 0) {
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0x3800;
        obj->state = 2;
    }
}
