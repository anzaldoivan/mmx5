/* Shared body (DK-5), from the banked draft of func_800EF928_ovl12 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_04/func_800EB5A0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK DEDUP_CALLEE(M2C_UNK*);
extern void (*D_800F1FF4_ovl12[])(void*);

void DEDUP_NAME(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800F1FF4_ovl12[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    DEDUP_CALLEE(arg0);
}
