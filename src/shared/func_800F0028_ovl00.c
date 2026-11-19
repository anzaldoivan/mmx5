/* Shared body (DK-5), from the banked draft of func_800F0028_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void DEDUP_NAME(Obj4FE0* e) {
    s32 d;

    move_object(e);
    d = D_8009A0AA - e->unkA;
    if (d >= 0 ? d < 0x20 : e->unkA - D_8009A0AA < 0x20) {
        set_animation(e, 2);
        e->unk6++;
        D_1F80004C.scr->unk86 = (random_byte() & 7) + 1;
    }
}
