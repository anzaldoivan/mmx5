/* Shared body (DK-5), from the banked draft of func_800F5364_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    set_animation(obj, 4);
    *(s16*)(obj + 0x7C) = (random_byte() & 3) * 10 + 0x20;
    obj[6]++;
}
