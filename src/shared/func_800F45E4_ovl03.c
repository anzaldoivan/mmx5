/* Shared body (DK-5), from the banked draft of func_800F45E4_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj4FE0*, s32);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_80017248(Obj4FE0*);
extern void func_8002DED4(Obj4FE0*);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA248_ovl03;

void DEDUP_NAME(Obj4FE0* obj) {
    s16 x;
    s16 a;

    func_800171E8(obj, 1);
    if (obj->unkA < D_800FA248_ovl03) {
        x = D_800FA240_ovl03 - 1;
        obj->unk15 = 0x40;
    } else {
        x = D_800FA242_ovl03 + 1;
        obj->unk15 = 0;
    }
    a = ratan2(D_800FA244_ovl03 - obj->unkE, x - obj->unkA);
    obj->unk20 = rcos(a) * 48;
    obj->unk24 = -rsin(a) * 48;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk6++;
    func_80017248(obj);
    func_8002DED4(obj);
}
