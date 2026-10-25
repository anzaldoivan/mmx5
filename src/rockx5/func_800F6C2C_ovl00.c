#include "types.h"

extern void func_8002DF54(Obj6C2C*);
extern void func_80032F70(Obj6C2C*);
extern void func_80033024(Obj6C2C*);
extern s32 func_800326BC(Obj6C2C*);
extern void func_8002D9EC(Obj6C2C*, s32, s32);
extern s32 func_8003240C(Obj6C2C*);
extern void func_8003258C(Obj6C2C*);

extern u8 D_8009A198;
extern void (*D_800FB3D0_ovl00[])(Obj6C2C*);

void func_800F6C2C_ovl00(Obj6C2C* obj) {
    func_8002DF54(obj);
    func_80032F70(obj);
    func_80033024(obj);
    func_800326BC(obj);
    D_800FB3D0_ovl00[obj->state](obj);
    func_8002D9EC(obj, 0x7F, 0x7F);
    if (D_8009A198 == 0 && obj->unk2 != 0x7F) {
        func_8003240C(obj);
    }
    func_8003258C(obj);
}
