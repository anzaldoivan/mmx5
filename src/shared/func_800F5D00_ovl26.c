/* Shared body (DK-5), from the banked draft of func_800F5D00_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Obj5D00* obj);
extern void func_800171E8(Obj5D00* obj, s32 state);
extern u8 D_800F9654_ovl26[];

void DEDUP_NAME(Obj5D00* obj) {
    func_80017248(obj);
    if (obj->unk7C[7] == 0) {
        func_800171E8(obj, 2);
        obj->unk5 = 1;
        obj->unk6 = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0x1000;
        obj->unk68 = D_800F9654_ovl26;
    }
}
