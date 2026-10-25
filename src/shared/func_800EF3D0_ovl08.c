/* Shared body (DK-5), from the banked draft of func_800EF3D0_ovl08 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EB10C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK); /* extern */
M2C_UNK func_80017248();               /* extern */
M2C_UNK func_8002DED4();               /* extern */
extern M2C_UNK D_800750C0;

void DEDUP_NAME(void* arg0) {
    ((M2C_UNK(*)())func_80017248)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800750C0;
        func_8002DED4(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            func_800171E8(arg0, 4);
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_800171E8(arg0, 1);
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 0;
    }
}
