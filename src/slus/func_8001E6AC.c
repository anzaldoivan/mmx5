/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D25C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012E0C(M2C_UNK, M2C_UNK*); /* extern */
extern M2C_UNK D_800D1F28;
void func_8001E534(void);

void func_8001E6AC(void) {
    M2C_FIELD(&D_800D1F28, s8*, 0) = 1;
    M2C_FIELD(&D_800D1F28, s8*, 1) = 0;
    M2C_FIELD(&D_800D1F28, s8*, 2) = 0;
    M2C_FIELD(&D_800D1F28, s8*, 3) = 0;
    func_80012E0C(0, &func_8001E534);
}
