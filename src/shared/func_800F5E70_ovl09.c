/* Shared body (DK-5), from the banked draft of func_800F5E70_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s16 D_800FB626_ovl09;

void DEDUP_NAME(u8* obj) {
    if (*(s16*)(obj + 0xE) >= D_800FB626_ovl09) {
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7C) = 20;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
