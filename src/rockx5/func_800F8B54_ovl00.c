#include "types.h"

extern void func_800171E8(Obj8B54*, s32);
extern void func_80017248(Obj8B54*);
extern void func_8002DED4(Obj8B54*);

void func_800F8B54_ovl00(Obj8B54* obj) {
    if (obj->flag46 == 0) {
        func_800171E8(obj, 1);
        obj->timer = 10;
        obj->count = 0;
        obj->state++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
