/* Shared body (DK-5), from the banked draft of func_800EF8CC_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern int DEDUP_CALLEE();
extern void (*D_800F5028_ovl05[])(Entity800EF8CC*);

void DEDUP_NAME(Entity800EF8CC* e) {
    e->prevX = e->x;
    e->prevY = e->y;
    if (*e->unk50 != 0x41) {
        DEDUP_CALLEE(e);
    } else {
        D_800F5028_ovl05[e->state](e);
    }
}
