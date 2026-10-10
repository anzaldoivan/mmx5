/* Shared body (DK-5), from the banked draft of func_800FC308_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct ObjFC308 {
    u8 pad0[0x7C];
    s16 timer; /* 0x7C */
} ObjFC308;

#define G (*(u8**)0x1F80004C)

void DEDUP_CALLEE(ObjFC308* self);

void DEDUP_NAME(ObjFC308* self) {
    if (--self->timer == -1) {
        G[0x92] = 0;
        DEDUP_CALLEE(self);
    }
}
