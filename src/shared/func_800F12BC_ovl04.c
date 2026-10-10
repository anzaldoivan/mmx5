/* Shared body (DK-5), from the banked draft of func_800F12BC_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Ent12BC {
    u8 pad0[5];
    u8 state; /* 0x05 */
    u8 sub;   /* 0x06 */
    u8 pad7[0x7C - 7];
    s16 timer; /* 0x7C */
} Ent12BC;

extern void DEDUP_CALLEE(Ent12BC*);

void DEDUP_NAME(Ent12BC* self) {
    if (--self->timer == -1) {
        self->state = 8;
        self->sub = 0;
    }
    DEDUP_CALLEE(self);
}
