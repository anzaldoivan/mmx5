/* Shared body (DK-5), from the banked draft of func_800EF334_ovl08 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EB070.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK); /* extern */
M2C_UNK func_80017248();               /* extern */
M2C_UNK func_8002DED4();               /* extern */

void DEDUP_NAME(void* arg0) {
    ((M2C_UNK(*)())func_80017248)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else {
        func_8002DED4(arg0);
        if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
            func_800171E8(arg0, 3);
            M2C_FIELD(arg0, s8*, 5) = 2;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
            M2C_FIELD(arg0, s8*, 6) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s8*, 0x67) = -1;
        }
    }
}
