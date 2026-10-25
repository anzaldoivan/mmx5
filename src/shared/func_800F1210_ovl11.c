/* Shared body (DK-5), from the banked draft of func_800F1210_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EBAAC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK DEDUP_CALLEE(void*, M2C_UNK);
extern M2C_UNK D_80074DA0;
extern s32 D_800F98E8_ovl11;
extern s32 D_800F98EC_ovl11;

void DEDUP_NAME(void* arg0) {
    void* temp_v1;

    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 0x60) = 5;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F98E8_ovl11;
    M2C_FIELD(arg0, void**, 0x58) = &D_80074DA0;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F98EC_ovl11;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F98E8_ovl11;
    M2C_FIELD(arg0, u8*, 4)++;
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) + 0x1A;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) - 0x1A;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(temp_v1, s16*, 0xE) - 0x23;
    } else {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) + 0x1A;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) - 0x1A;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(temp_v1, s16*, 0xE) - 0x10;
    }
    DEDUP_CALLEE(arg0, 7);
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 0x8F) = 0x20;
    M2C_FIELD(arg0, u8*, 0x8D) = 0;
    M2C_FIELD(arg0, u8*, 0x8E) = 0;
    M2C_FIELD(arg0, u8*, 0x92) = 0;
    M2C_FIELD(arg0, u8*, 0x90) = 2;
    M2C_FIELD(arg0, u8*, 0x91) = 0;
    M2C_FIELD(arg0, u8*, 0x93) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, s8*, 0x8C) = M2C_FIELD(arg0, s8*, 2) * 0x14 + 0x1E;
}
