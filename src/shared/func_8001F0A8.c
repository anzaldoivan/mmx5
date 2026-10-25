/* Shared body (DK-5), from the banked draft of func_8001F0A8 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DDB0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_80012E0C(M2C_UNK, M2C_UNK*); /* extern */
M2C_UNK func_80012EAC();                  /* extern */
extern M2C_UNK func_80020904;

void DEDUP_NAME(void) {
    func_80012E0C(1, &func_80020904);
    func_80012EAC();
}
