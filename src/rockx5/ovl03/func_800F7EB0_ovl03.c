#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern Tbl7EB0 D_800EE9DC_ovl03;

void func_800F7EB0_ovl03(Ent7EB0* obj) {
    Tbl7EB0 tbl = D_800EE9DC_ovl03;

    if (tbl.b[obj->unk7] != 0) {
        obj->unk24 = 0x30000;
    } else {
        obj->unk24 = -0x30000;
    }
    obj->unk6++;
    animate_object(obj);
    apply_object_motion(obj);
}
