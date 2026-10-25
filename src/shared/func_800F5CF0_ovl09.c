/* Shared body (DK-5), from the banked draft of func_800F5CF0_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj5CF0*, s32);
extern void func_80017248(Obj5CF0*);
extern void func_8002DED4(Obj5CF0*);
extern s32 D_800FB67C_ovl09;
extern s16 D_800FB680_ovl09;

void DEDUP_NAME(Obj5CF0* obj) {
    func_800171E8(obj, 5);
    obj->unk20 = 0;
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk7C = 0;
    if (D_800FB67C_ovl09 != 0) {
        D_800FB680_ovl09 = 0x78;
    } else {
        D_800FB680_ovl09 = 0xF0;
    }
    obj->state++;
    func_80017248(obj);
    func_8002DED4(obj);
}
