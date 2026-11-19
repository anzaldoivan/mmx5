/* Shared body (DK-5), from the banked draft of func_800FC398_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    func_800FC9E0_ovl07(obj);
    set_animation(obj, 7);
    obj[6]++;
}
