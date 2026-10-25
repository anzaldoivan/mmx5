/* Shared body (DK-5), from the banked draft of func_800EF190_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern X4_Obj D_8009A0A0;

void DEDUP_NAME(X4_Obj* self) {
    s32 d;

    if ((u8)(self->unk5 - 5) < 2) {
        return;
    }
    d = D_8009A0A0.y_pos.i.hi - self->y_pos.i.hi;
    if (d >= 0 ? d < 0x20 : self->y_pos.i.hi - D_8009A0A0.y_pos.i.hi < 0x20) {
        d = D_8009A0A0.x_pos.i.hi - self->x_pos.i.hi;
        if (d >= 0 ? d < 0x60
                   : self->x_pos.i.hi - D_8009A0A0.x_pos.i.hi < 0x60) {
            if (!(self->unk70 & 3)) {
                if (self->unk15 == 0 ? D_8009A0A0.x_pos.val < self->x_pos.val
                                     : D_8009A0A0.x_pos.val > self->x_pos.val) {
                    self->unk80 = 1;
                }
            }
        }
    }
    if (self->unk5 == 2 && self->unk80 != 0) {
        self->unk5 = 4;
        self->unk6 = 0;
        self->x_vel.val = 0;
        self->unk28 = 0;
    }
}
