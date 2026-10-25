/* Shared body (DK-5), from the banked draft of func_800F0D54_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

void func_80017248(X4_Obj*);
void func_800F1074_ovl11(X4_Obj*);

void DEDUP_NAME(X4_Obj* self) {
    func_80017248(self);
    if (--self->unk7C == 0) {
        func_800F1074_ovl11(self);
        self->unk7C = 0x3C;
        self->unk6++;
    }
}
