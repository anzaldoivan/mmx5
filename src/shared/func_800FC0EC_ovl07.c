/* Shared body (DK-5), from the banked draft of func_800FC0EC_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "addr.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (ABS(*(s16*)(D_1F80004C.bytes + 0x84) - *(s16*)(obj + 0xE)) < 8) {
        obj[6] = 3;
    }
}
