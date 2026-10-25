#include "types.h"

extern void func_80017248(Ent9364*);
extern u8 D_800FA2E0_ovl29[][6];

void func_800F5434_ovl29(Ent9364* obj) {
    func_80017248(obj);
    if (obj->unk46 == 0) {
        obj->unk5 = D_800FA2E0_ovl29[obj->unk8D][obj->unk8E];
        obj->unk8E++;
        obj->unk6 = 0;
    }
}
