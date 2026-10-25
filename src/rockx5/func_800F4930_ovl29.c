#include "types.h"

extern void func_80017248(Ent8EF4*);
extern u8 D_800FA2E0_ovl29[][6];

void func_800F4930_ovl29(Ent8EF4* obj) {
    func_80017248(obj);
    if (--obj->unk7C == 0) {
        obj->unk5 = D_800FA2E0_ovl29[obj->unk8D][obj->unk8E];
        obj->unk8E++;
        obj->unk6 = 0;
    }
}
