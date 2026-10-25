/* Shared body (DK-5), from the banked draft of func_800F5C44_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj3DD4*, s32);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_80017248(Obj3DD4*);
extern void func_8002DED4(Obj3DD4*);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA248_ovl03;

void DEDUP_NAME(Obj3DD4* obj) {
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
        a = ratan2(D_800FA244_ovl03 - e, x - obj->unkA);
        obj->unk20 = rcos(a) * 48;
        obj->unk24 = -rsin(a) * 48;
        obj->unk6++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
