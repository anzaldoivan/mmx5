/* Shared body (DK-5), from the banked draft of func_800F150C_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj150C* s) {
    if (D_8009A0AA - s->b.unkA > 0) {
        s->b.unk15 = 0x40;
    }
    set_animation(s, 1);
    animate_object(s);
    s->unk7C = 0x28;
    s->unk7E = 0x20;
    s->b.unk20 = 0;
    s->b.unk28 = 0;
    s->b.unk24 = 0xFFFE0000;
    s->b.unk2C = 0;
    s->b.unk6++;
}
