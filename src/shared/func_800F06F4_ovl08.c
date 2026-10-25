/* Shared body (DK-5), from the banked draft of func_800F06F4_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Obj06F4*);
extern void func_800171E8(Obj06F4*, s32);

void DEDUP_NAME(Obj06F4* obj) {
    func_80017248(obj);
    if (obj->unk45 != 0) {
        obj->unk15 ^= 0x40;
        func_800171E8(obj, 1);
        obj->unk7C = 20;
        if (obj->unk8A == 0) {
            obj->unk6 = 2;
        } else {
            if (obj->unk15 != 0) {
                obj->unk20 = 0x40000;
            } else {
                obj->unk20 = -0x40000;
            }
            func_800171E8(obj, 7);
            obj->unk5 = 7;
            obj->unk6 = 1;
        }
    }
}
