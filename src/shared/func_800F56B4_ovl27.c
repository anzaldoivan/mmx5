/* Shared body (DK-5), from the banked draft of func_800F56B4_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "addr.h"

void DEDUP_NAME(Obj3DD4* o) {
    u32 r;

    set_animation(o, 2);
    D_1F80004C.bytes[0x88] = 1;
    r = random_byte();
    o->unk6++;
    o->unk7C = (u8)(r % 120) + 60;
}
