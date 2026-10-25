/* Shared body (DK-5), from the banked draft of func_800F06B8_ovl12 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_45/func_800FBE94.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016490(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017248(void*);                   /* extern */
M2C_UNK func_8002DED4(void*);                   /* extern */

void DEDUP_NAME(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        func_80016490(2, 0x38, arg0);
        func_80016490(2, 0x5C, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    func_80017248(arg0);
    func_8002DED4(arg0);
}
