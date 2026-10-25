/* Shared body (DK-5), from the banked draft of func_800EF294_ovl08 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EAFD0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D938(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK);
s32 func_8003157C(void*, s16, s16);
extern M2C_UNK D_800F39DC_ovl08;
extern M2C_UNK D_800F39E4_ovl08;

void DEDUP_NAME(void* arg0) {
    if (!(func_8003157C(arg0, M2C_FIELD(arg0, s16*, 0xA),
                        M2C_FIELD(arg0, s16*, 0xE)) &
          0xFF)) {
        M2C_FIELD(arg0, u8*, 4) = 1;
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 2) = 0;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E4_ovl08;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39DC_ovl08;
    }
    if (func_8002D938(arg0, 0x40, 0x40) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 2) {
            func_8002D9EC(arg0, 0x25, 0x25);
        }
    } else {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
