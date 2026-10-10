/* Shared body (DK-5), from the banked draft of func_800F0470_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj0470*, s32);
extern void func_80017248(Obj0470*);
extern void func_8002DED4(Obj0470*);
extern u8 D_800F1F94_ovl12[][6];

void DEDUP_NAME(Obj0470* obj) {
    if (++obj->unk7C == 100) {
        func_800171E8(obj, 9);
    }
    if (obj->unk46 == 0) {
        func_800171E8(obj, 1);
        obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87++];
        obj->unk6 = 0;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
