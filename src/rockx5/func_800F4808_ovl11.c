#include "types.h"

extern void func_80032F70(Obj4808*);
extern void func_80033024(Obj4808*);
extern s32 func_800326BC(Obj4808*);
extern void func_8002D9EC(Obj4808*, s32, s32);
extern s32 func_8003240C(Obj4808*);
extern void func_8003258C(Obj4808*);

extern u8 D_8009A198;
extern void (*D_800F9C64_ovl11[])(Obj4808*);

void func_800F4808_ovl11(Obj4808* obj) {
    func_80032F70(obj);
    func_80033024(obj);
    D_800F9C64_ovl11[obj->state](obj);
    func_800326BC(obj);
    func_8002D9EC(obj, 0x60, 0x60);
    if (D_8009A198 == 0) {
        func_8003240C(obj);
    }
    func_8003258C(obj);
}
