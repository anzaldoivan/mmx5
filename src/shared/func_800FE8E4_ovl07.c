/* Shared body (DK-5), from the banked draft of func_800FE8E4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ent800FE1E8*);
extern u8 D_80101DD0_ovl07[];
extern u8 D_80101DB8_ovl07[];
extern u8 D_80101DC4_ovl07[];

void DEDUP_NAME(Ent800FE1E8* o) {
    if (o->unk45 == 2) {
        o->unk68 = D_80101DD0_ovl07;
        o->unk50 = D_80101DB8_ovl07;
        o->unk54 = D_80101DC4_ovl07;
        o->unk8D = 1;
        o->unk15 = 0;
        o->unk8C = 1;
        o->unk5 = 0;
        o->unk6 = 0;
    }
    DEDUP_CALLEE(o);
}
