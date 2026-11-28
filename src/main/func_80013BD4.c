/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800144AC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK setup_file_load(M2C_UNK, M2C_UNK, M2C_UNK);
void pump_file_loads(void);

void func_80013BD4(void) {
    setup_file_load(0, 0, 0);
    pump_file_loads();
}
