/* Shared body (DK-5), from the banked draft of func_800F6F70_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj6F70* obj, s32 state);

void DEDUP_NAME(Obj6F70* obj) {
    obj->unk16 = 3;
    obj->unk4 = 1;
    obj->unk5 = 0;
    obj->unk3 = 1;
    obj->unk58 = 0;
    obj->unk61 = 1;
    obj->unk90 = 0;
    obj->unk94 = 0;
    obj->unk20 = 0;
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk68 = 0;
    obj->unk54 = 0;
    obj->unk50 = 0;
    obj->unk5C = 0;
    obj->unk60 = 0;
    obj->unk84 = 0;
    DEDUP_CALLEE(obj, 0x18);
}
