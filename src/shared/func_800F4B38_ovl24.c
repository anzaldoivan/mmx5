/* Shared body (DK-5), from the banked draft of func_800F4B38_ovl24 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_18/func_800EF7E4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern X4_EngineObj D_8009A420;
extern u8 D_800D1C28;
extern u16 D_800F5A1C_ovl24[][2];

void DEDUP_NAME(void* arg0) {
    if (D_800D1C28 == 0x7F) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800D1C28 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
    M2C_FIELD(arg0, u16*, 0xA) = D_800F5A1C_ovl24[(u8)D_8009A420.unk7][0];
    M2C_FIELD(arg0, u16*, 0xE) = D_800F5A1C_ovl24[(u8)D_8009A420.unk7][1];
}
