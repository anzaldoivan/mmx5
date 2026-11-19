#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800F9894_ovl29[];
extern u8 D_800FA2E0_ovl29[][6];

void func_800F4D08_ovl29(Ent4D08* obj) {
    animate_object(obj);
    if (obj->unk46 == 0) {
        obj->unk50 = D_800F9894_ovl29;
        obj->unk5 = D_800FA2E0_ovl29[obj->unk8D][obj->unk8E];
        obj->unk8E++;
        obj->unk6 = 0;
    }
}
