/* Adapted from mmx6 @c1c892d src/shared/rock_04/func_800EB5A0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void (*D_800F1FF4_ovl12[])(void*);

void func_800EF928_ovl12(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800F1FF4_ovl12[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002FB58(arg0);
}
