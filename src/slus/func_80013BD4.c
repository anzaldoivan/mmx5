/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800144AC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_80014684(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void pump_file_loads(void);                       /* extern */

void func_80013BD4(void) {
    func_80014684(0, 0, 0);
    pump_file_loads();
}
