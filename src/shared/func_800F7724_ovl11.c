/* Shared body (DK-5), from the banked draft of func_800F7724_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Ent7724* e) {
    u32 r;

    if (e->unkA > D_8009A0AA) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    move_object(e);
    animate_object(e);
    if (--e->unk7C == 0) {
        set_animation(e, 2);
        e->unk7C = 90;
        r = random_byte();
        e->unk6++;
        e->unk7E = (u8)(r % 3) + 2;
    }
}
