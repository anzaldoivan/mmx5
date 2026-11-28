/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DDB0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK create_task(M2C_UNK, M2C_UNK*);
M2C_UNK func_80012EAC();
extern M2C_UNK func_80020904;

void func_8001F0A8(void) {
    create_task(1, &func_80020904);
    func_80012EAC();
}
