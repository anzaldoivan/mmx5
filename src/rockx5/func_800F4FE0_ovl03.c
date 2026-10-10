#include "types.h"

extern void func_800171E8(Obj4FE0*, s32);
extern s32 func_80068058(s32, s32);
extern s32 func_80067EF8(s32);
extern s32 func_80067E28(s32);
extern void func_80017248(Obj4FE0*);
extern void func_8002DED4(Obj4FE0*);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA248_ovl03;
extern s16 D_800FA24E_ovl03;

void func_800F4FE0_ovl03(Obj4FE0* obj) {
    s16 x;
    s16 a;
    s32 e;

    func_800171E8(obj, 1);
    if (obj->unkA < D_800FA248_ovl03) {
        x = D_800FA240_ovl03 - 1;
        obj->unk15 = 0x40;
    } else {
        x = D_800FA242_ovl03 + 1;
        obj->unk15 = 0;
    }
    e = obj->unkE - 1;
    a = func_80068058(D_800FA24E_ovl03 - e, x - obj->unkA);
    obj->unk20 = func_80067EF8(a) * 48;
    obj->unk24 = -func_80067E28(a) * 48;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk6++;
    func_80017248(obj);
    func_8002DED4(obj);
}
