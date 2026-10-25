/* Shared body (DK-5), from the banked draft of func_800FBC80_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(ObjBB70*);
extern s32 func_8002F8FC(ObjBB70*);

extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void DEDUP_NAME(ObjBB70* obj) {
    func_8002DF54(obj);
    if (obj->unk47 == 0xB) {
        obj->unk50 = D_800FF684_ovl06;
        obj->unk54 = D_800FF688_ovl06;
    }
    if (obj->unk70 == 0) {
        func_8002F8FC(obj);
        if (obj->unk70 == 0) {
            return;
        }
    }
    obj->unk50 = D_800FF684_ovl06;
    obj->unk54 = D_800FF688_ovl06;
    obj->unk4 = 3;
    obj->unk7 = 0;
}
