/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001EC40.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_80034A04();     /* extern */
M2C_UNK read_player_input(); /* extern */

void func_80020F78(void) {
    read_player_input();
    func_80034A04();
}
