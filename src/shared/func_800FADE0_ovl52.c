/* Shared body (DK-5), from the banked draft of func_800FADE0_ovl52 by tools/wave/gate.py rescan. */
#include "types.h"

/* e: Ovl45State (include/types.h), same shape as this function's accesses */
extern void DEDUP_CALLEE(s32, s32, s32, void*);
extern u8 D_800FB0D8_ovl52[];
extern u8 D_8009A298;

void DEDUP_NAME(Ovl45State* e) {
    if (++e->unk4 >= 8) {
        DEDUP_CALLEE(1, 0x340, 0x240, D_800FB0D8_ovl52);
        D_8009A298 = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}
