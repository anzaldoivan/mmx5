/* Shared body (DK-5), from the banked draft of func_800EF82C_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

void func_8002DF54(ObjEF82C*);
void func_80017248(ObjEF82C*);

extern s32 D_8009A0A8;

void DEDUP_NAME(ObjEF82C* self) {
    self->unk84 += 4;
    if (self->unk84 < 0 ||
        (self->unk15 == 0 ? D_8009A0A8 > self->x : D_8009A0A8 < self->x)) {
        self->unk28 = -0x1800;
        self->unk6 = 2;
    }
    if (((self->unk70 & 2) && self->unk15 == 0) ||
        ((self->unk70 & 1) && self->unk15 != 0)) {
        self->unk60 = 3;
        self->unk28 = 0;
        self->unk20 = 0;
        self->unk5 = 7;
        self->unk6 = 0;
    }
    func_8002DF54(self);
    func_80017248(self);
}
