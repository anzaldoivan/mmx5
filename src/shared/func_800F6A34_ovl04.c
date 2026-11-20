/* Shared body (DK-5), from the banked draft of func_800F6A34_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    u8* plr;
    s32 target;

    animate_object(obj);
    plr = g_Player;
    if (*(s16*)(plr + 0xA) < *(s16*)(obj + 0xA)) {
        target = *(s16*)(plr + 0xE) - 8;
        if (*(s16*)(obj + 0xE) < target) {
            *(s16*)(obj + 0xE) += 1;
        } else if (target < *(s16*)(obj + 0xE)) {
            *(s16*)(obj + 0xE) -= 1;
        }
    }
    move_object(obj);
}
