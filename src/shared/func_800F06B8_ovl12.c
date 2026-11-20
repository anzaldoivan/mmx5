/* Shared body (DK-5), from the banked draft of func_800F06B8_ovl12 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_45/func_800FBE94.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void DEDUP_NAME(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        play_sound(2, 0x38, arg0);
        play_sound(2, 0x5C, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    animate_object(arg0);
    apply_object_motion(arg0);
}
