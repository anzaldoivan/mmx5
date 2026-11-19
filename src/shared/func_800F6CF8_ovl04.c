/* Shared body (DK-5), from the banked draft of func_800F6CF8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* a0) {
    move_object(a0);
    animate_object(a0);
    if (*(s16*)(a0 + 0xE) < 0x11) {
        a0[0x8F] = 0x1E;
        a0[0x6] = 2;
    }
}
