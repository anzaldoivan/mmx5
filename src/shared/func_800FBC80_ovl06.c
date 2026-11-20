/* Shared body (DK-5), from the banked draft of func_800FBC80_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void DEDUP_NAME(ObjBB70* obj) {
    move_object(obj);
    if (obj->unk47 == 0xB) {
        obj->unk50 = D_800FF684_ovl06;
        obj->unk54 = D_800FF688_ovl06;
    }
    if (obj->unk70 == 0) {
        ((s32(*)())func_8002F8FC)(obj);
        if (obj->unk70 == 0) {
            return;
        }
    }
    obj->unk50 = D_800FF684_ovl06;
    obj->unk54 = D_800FF688_ovl06;
    obj->unk4 = 3;
    obj->unk7 = 0;
}
