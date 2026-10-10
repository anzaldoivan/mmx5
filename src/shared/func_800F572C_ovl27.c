/* Shared body (DK-5), from the banked draft of func_800F572C_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"

#define D_1F80004C (*(u8**)0x1F80004C)

extern void DEDUP_CALLEE(Obj800F2688*);

void DEDUP_NAME(Obj800F2688* self) {
    if (--self->unk7C == 0) {
        DEDUP_CALLEE(self);
        D_1F80004C[0x88] = 0;
    }
}
