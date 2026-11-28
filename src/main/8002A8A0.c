#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80071B0C[];

void func_8002A8A0(u8* arg0) {
    u8* t = D_80071B0C;
    s8* p = g_playthrough_state.s;
    arg0[4] = t[p[0xD] * 2 + p[0xC] * 4];
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002974C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

M2C_UNK func_8002A960(s32);
M2C_UNK func_8002A980();
void func_8002A9A0(X4_BackgroundObj* arg0);

void func_8002A8D4(s32 arg0) {
    func_8002A980();
    func_8002A960(arg0);
    func_8002A9A0(arg0);
}
