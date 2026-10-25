/* Shared body (DK-5), from the banked draft of func_800F0AD0_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(void*, s32);

void DEDUP_NAME(Obj5CF0* obj) {
    func_80016490(2, 0x3E, obj);
    func_800171E8(obj, 10);
    obj->unk20 = 0;
    obj->unk24 = 0x20000;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk7C = 0;
    obj->state++;
}
