/* Shared body (DK-5), from the banked draft of func_800EFAE4_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(ObjEFAE4*, s32);
extern void func_80017248(ObjEFAE4*);
extern u8 D_800750C0[];
extern u8 D_800F8FB8_ovl29[];
extern u8 D_800F8FBC_ovl29[];

void DEDUP_NAME(ObjEFAE4* obj) {
    switch (obj->unk45) {
    case 1:
        obj->unk5 = 2;
        obj->unk20 = 0;
        obj->unk6 = 0;
        func_800171E8(obj, 1);
        break;
    case 2:
        obj->unk54 = D_800F8FBC_ovl29;
        obj->unk50 = D_800F8FB8_ovl29;
        break;
    case 3:
        obj->unk58 = D_800750C0;
        break;
    }
    func_80017248(obj);
}
