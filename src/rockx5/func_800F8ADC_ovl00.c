#include "types.h"

extern u8 D_800FB448_ovl00[][6];
extern void func_80017248(Ent9364*);
extern void func_8002DED4(Ent9364*);

void func_800F8ADC_ovl00(Ent9364* obj) {
    if (obj->unk46 == 0) {
        obj->unk5 = D_800FB448_ovl00[obj->unk8D][obj->unk8E++];
        obj->unk6 = 0;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
