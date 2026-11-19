/* Shared body (DK-5), from the banked draft of func_800F0FB0_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl05.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

extern s32 func_800F0FFC_ovl05(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_800F103C_ovl05(obj);
    apply_object_motion(obj);
    if (func_800F0FFC_ovl05(obj) != 0) {
        obj[3] = 0;
        ((s32(*)())func_8004FD24)(obj);
        obj[4] = 2;
    }
}
