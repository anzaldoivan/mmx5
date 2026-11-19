#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern u8 D_800FB448_ovl00[][6];

void func_800F8EF4_ovl00(Ent8EF4* obj) {
    if (--obj->unk7C == -1) {
        obj->unk5 = D_800FB448_ovl00[obj->unk8D][obj->unk8E++];
        obj->unk6 = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
