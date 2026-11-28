/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003A980.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_clear_attack();
void clear_flash_palette(void* arg0);

void cancel_player_attack(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xCF) = 1;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s8*, 0x8C) = 0;
    player_clear_attack();
    clear_flash_palette(arg0);
}
