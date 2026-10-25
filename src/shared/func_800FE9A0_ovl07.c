/* Shared body (DK-5), from the banked draft of func_800FE9A0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800317B8(EntFE9A0*);
extern void func_80017248(EntFE9A0*);
extern void func_800FEBCC_ovl07(EntFE9A0*, s32, s32, s32);

void DEDUP_NAME(EntFE9A0* e) {
    func_800317B8(e);
    func_80017248(e);
    if (--e->timer == -1) {
        func_800FEBCC_ovl07(e, e->x, e->y, 5);
        func_800FEBCC_ovl07(e, e->x, e->y, 6);
        e->state = 2;
    }
}
