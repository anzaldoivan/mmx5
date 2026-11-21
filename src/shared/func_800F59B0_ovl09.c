#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FADFC_ovl09[])(Ent59B0*);

void func_800F59B0_ovl09(Ent59B0* obj) {
    if (D_8009A0AA > obj->unkA) {
        obj->unk15 = 0x40;
    } else {
        obj->unk15 = 0;
    }
    D_800FADFC_ovl09[obj->unk6](obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
