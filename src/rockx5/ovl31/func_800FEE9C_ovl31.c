#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern Tbl7EB0 D_800FA004_ovl31;

void func_800FEE9C_ovl31(Ent7EB0* obj) {
    Tbl7EB0 tbl = D_800FA004_ovl31;

    if (tbl.b[obj->unk7] != 0) {
        obj->unk24 = 0x30000;
    } else {
        obj->unk24 = -0x30000;
    }
    obj->unk6++;
    animate_object(obj);
    apply_object_motion(obj);
}
