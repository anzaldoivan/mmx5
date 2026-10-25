#include "types.h"

extern void func_80017248(Obj88E0*);
extern void func_8002DED4(Obj88E0*);

void func_800F88E0_ovl00(Obj88E0* obj) {
    if (obj->flag46 == 0) {
        obj->unk28 = 0x2000;
        obj->timer = 0;
        obj->state++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
