#include "types.h"

extern void func_80017248(Obj8B54*);
extern void func_8002DED4(Obj8B54*);

void func_800F9200_ovl00(Obj8B54* obj) {
    if (obj->flag46 == 0) {
        obj->timer = 1;
        obj->count = 0;
        obj->state++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
