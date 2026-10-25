#include "types.h"

extern void func_8002D9EC(ObjFA798* obj, s32 a, s32 b);
extern void func_80017248(ObjFA798* obj);
extern void func_8002DF54(ObjFA798* obj);

void func_800FAA18_ovl28(ObjFA798* obj) {
    if (obj->f46 == 0) {
        obj->f4 = 2;
    }
    if (obj->parent->state == 2) {
        obj->f4 = 2;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    func_80017248(obj);
    func_8002DF54(obj);
}
