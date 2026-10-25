/* Shared body (DK-5), from the banked draft of func_800FBB70_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DED4(ObjBB70*);
extern s32 func_8002F8FC(ObjBB70*);
extern void func_800171E8(ObjBB70*, s32);

extern u8 D_800FF69C_ovl06[];
extern u8 D_800FF6A0_ovl06[];
extern u8 D_800FF6A4_ovl06[];

void DEDUP_NAME(ObjBB70* obj) {
    func_8002DED4(obj);
    if (obj->unk70 == 0) {
        func_8002F8FC(obj);
        if (obj->unk70 == 0) {
            return;
        }
    }
    if (obj->unk70 & 4) {
        if (obj->unk70 & 1) {
            obj->unk15 = 0;
        } else if (obj->unk70 & 2) {
            obj->unk15 = 0x40;
        }
    }
    func_800171E8(obj, 1);
    obj->unk68 = D_800FF6A4_ovl06;
    obj->unk50 = D_800FF69C_ovl06;
    obj->unk54 = D_800FF6A0_ovl06;
    obj->state++;
}
