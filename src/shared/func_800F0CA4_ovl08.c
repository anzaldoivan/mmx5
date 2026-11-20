/* Shared body (DK-5), from the banked draft of func_800F0CA4_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    if (*(s32*)(obj + 0x8C) != 1) {
        *(s32*)(obj + 0x8C) = *(s32*)(obj + 0x8C) - 1;
    }
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) == 0) {
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(u8*)(obj + 0x88) = 0;
        *(s16*)(obj + 0x7C) = 10;
        *(u8*)(obj + 0x6) = 3;
    }
}
