/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC6C4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);
extern u8 D_800F95AC_ovl03[];
extern ObjFAFFC D_800F959C_ovl03;

void func_800EF804_ovl03(void* arg0) {
    // !FAKE: pins tbl to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 tbl asm("$3");
    // !FAKE: pins v to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 v asm("$4");

    func_800171E8(arg0, 3);
    tbl = (s32)(D_800F95AC_ovl03);
    v = *(s32*)((M2C_FIELD(arg0, u8*, 0x15) >> 4 & 4) + tbl);
    {
        // !FAKE: pins a to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
        register void* a asm("$2") = &D_800F959C_ovl03;
        M2C_FIELD(arg0, void**, 0x50) = a;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 1;
    {
        // !FAKE: pins b to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 b asm("$3") = M2C_FIELD(arg0, u8*, 0x6);
        M2C_FIELD(arg0, u8*, 0x6) = b + 1;
    }
    M2C_FIELD(arg0, s32*, 0x20) = v;
}
