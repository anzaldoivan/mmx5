#include "types.h"

extern void func_800171E8(Obj3DD4*, s32);
extern s32 func_80068058(s32, s32);
extern s32 func_80067EF8(s32);
extern s32 func_80067E28(s32);
extern void func_80017248(Obj3DD4*);
extern void func_8002DED4(Obj3DD4*);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA248_ovl03;

void func_800F5C44_ovl03(Obj3DD4* obj) {
    s16 x;
    s16 a;
    s32 e;

    if (++obj->unk7C == 20) {
        func_800171E8(obj, 1);
        if (obj->unkA < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 16;
        } else {
            x = D_800FA242_ovl03 + 16;
        }
        e = obj->unkE + 1;
        a = func_80068058(D_800FA244_ovl03 - e, x - obj->unkA);
        obj->unk20 = func_80067EF8(a) * 48;
        obj->unk24 = -func_80067E28(a) * 48;
        obj->unk6++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
