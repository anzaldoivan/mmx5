/* Shared body (DK-5), from the banked draft of func_800EFF50_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern ObjEFF50* func_8002D1A4();

void DEDUP_NAME(ObjEFF50* self) {
    ObjEFF50* obj;

    if (self->unk45 != 0) {
        func_80016490(2, 0x37, self);
        func_80016490(2, 0x43, self);
        obj = func_8002D1A4();
        if (obj != 0) {
            obj->unk0 = 0x41;
            obj->unk1 = 0x18;
            obj->unk2 = 0;
            obj->unk7C = self;
        }
        self->unk7 = 0;
        self->unk6++;
    }
}
