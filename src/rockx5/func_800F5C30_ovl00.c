#include "types.h"

extern void func_80032F70(Obj5C30*);
extern void func_80033024(Obj5C30*);
extern s32 func_800326BC(Obj5C30*);
extern void func_8002D9EC(Obj5C30*, s32, s32);
extern void func_8002FB58(Obj5C30*);
extern s32 func_8003240C(Obj5C30*);
extern void func_8003258C(Obj5C30*);

extern u8 D_8009A198;
extern void (*D_800FB29C_ovl00[])(Obj5C30*);

void func_800F5C30_ovl00(Obj5C30* obj) {
    func_80032F70(obj);
    func_80033024(obj);
    func_800326BC(obj);
    D_800FB29C_ovl00[obj->state](obj);
    func_8002D9EC(obj, 0xFF, 0x20);
    func_8002FB58(obj);
    if (D_8009A198 == 0) {
        func_8003240C(obj);
    }
    func_8003258C(obj);
}
