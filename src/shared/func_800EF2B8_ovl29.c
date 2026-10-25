/* Shared body (DK-5), from the banked draft of func_800EF2B8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern X4_Obj D_8009A0A0;
extern s16 D_8009A0AE;

void DEDUP_NAME(ObjEECF8* self) {
    s32 d;

    if (self->unk5 != 2) {
        return;
    }
    if (self->unk88 == 0) {
        d = D_8009A0A0.y_pos.i.hi - self->y.i.hi;
        if (d >= 0 ? d < 0x20 : self->y.i.hi - D_8009A0A0.y_pos.i.hi < 0x20) {
            if (self->unk15 == 0 ? D_8009A0A0.x_pos.val < self->x.val
                                 : D_8009A0A0.x_pos.val > self->x.val) {
                self->unk88 = 1;
            }
        }
    } else {
        d = D_8009A0AE - self->y.i.hi;
        if (d >= 0 ? d >= 0x21 : self->y.i.hi - D_8009A0AE >= 0x21) {
            self->unk88 = 0;
            self->unk8C = 0x78;
        }
    }
}
