/* Shared body (DK-5), from the banked draft of func_80020F78 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001EC40.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_80034A04();     /* extern */
M2C_UNK read_player_input(); /* extern */

void DEDUP_NAME(void) {
    read_player_input();
    func_80034A04();
}
