#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_80032F70(Obj6C2C*);
extern s32 func_800326BC(Obj6C2C*);
extern s32 func_8003240C(Obj6C2C*);
extern void func_8003258C(Obj6C2C*);

extern u8 D_8009A198;
extern void (*D_800FB3D0_ovl00[])(Obj6C2C*);

void func_800F6C2C_ovl00(Obj6C2C* obj) {
    move_object(obj);
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

extern void func_80017768(void);
extern s8 D_800D1C1D;

void func_800F6CD0_ovl00(u8* obj) {
    func_8002D9EC(obj, 0x7F, 0x7F);
    if (((s8*)obj)[2] == 1) {
        if (D_800D1C1D == 3) {
            func_80017768();
            func_8002D720(obj);
        }
    } else if (((s8*)obj)[2] == 0x70) {
        obj[3] = 0;
        if (D_800D1C1D == 3) {
            obj[3] = 1;
        }
    }
}
