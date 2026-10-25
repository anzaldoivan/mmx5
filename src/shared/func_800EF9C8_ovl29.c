/* Shared body (DK-5), from the banked draft of func_800EF9C8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(ObjEF9C8*, s32);
extern void func_80017248(ObjEF9C8*);
extern void func_8002DED4(ObjEF9C8*);
extern u8 D_800750C0[];

void DEDUP_NAME(ObjEF9C8* obj) {
    func_80017248(obj);
    if (obj->unk70 & 8) {
        if (obj->unk80 != 0) {
            obj->unk58 = D_800750C0;
            obj->unk60 = 3;
            obj->unk5 = 7;
        } else {
            func_800171E8(obj, 1);
            obj->unk5 = 2;
        }
        obj->unk6 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk67 = 0;
        return;
    }
    func_8002DED4(obj);
}
