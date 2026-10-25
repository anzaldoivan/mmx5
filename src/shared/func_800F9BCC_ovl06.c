/* Shared body (DK-5), from the banked draft of func_800F9BCC_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800FAEF8_ovl06(Obj8AA8*);
extern void func_800171E8(Obj8AA8*, s32);
extern s32 D_800FF1DC_ovl06[];
extern s32 D_800FF1E0_ovl06[];

void DEDUP_NAME(Obj8AA8* obj) {
    func_800FAEF8_ovl06(obj);
    func_800171E8(obj, 0x13);
    obj->unk50 = D_800FF1DC_ovl06;
    obj->unk54 = D_800FF1E0_ovl06;
    if (obj->unk15 == 0) {
        obj->unk20 = 0xFFFDE9BE;
    } else {
        obj->unk20 = 0x21642;
    }
    obj->unk28 = 0;
    obj->unk24 = 0x85502;
    obj->unk2C = 0x5CBD;
    obj->unk6++;
}
