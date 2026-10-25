/* Shared body (DK-5), from the banked draft of func_800FA908_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(X4_Obj* self) {
    if (--self->unk7C == 0) {
        self->unk6 = 2;
        *(s16*)((u8*)self + 0x7E) = 0;
    }
}
