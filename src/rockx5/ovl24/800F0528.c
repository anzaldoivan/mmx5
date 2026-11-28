#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A169;
extern u16 D_800F4E90_ovl24[][8];
extern s32 get_launch_variant(void);

void func_800F0528_ovl24(u8* a0) {
    u8* p = g_playthrough_state.u;
    u8 v = p[0x26];

    if ((u32)(v - 1) < 8 && ((s8*)p)[0x27] == 0 &&
        !((D_8009A169 >> ((s8)v - 1)) & 1)) {
        func_8002385C(
            D_800F4E90_ovl24[get_launch_variant()][((s8*)p)[0x26] - 1], 0xFF,
            0);
        a0[2]++;
        return;
    }
    a0[1] = 5;
    a0[2] = 0;
}

/* Adapted from mmx6 @c1c892d src/shared/rock_20/func_800EECD8.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80091C44;

void func_800F05FC_ovl24(void* arg0) {
    if (D_80091C44 == 0) {
        M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    }
}
#undef M2C_FIELD

extern u8 D_8009A169;
extern void func_800EEB30_ovl24(void);

void func_800F0628_ovl24(u8* a0) {
    u8* p = g_playthrough_state.u;
    u8 v = p[0x26];

    if ((u32)(v - 1) < 8 && ((s8*)p)[0x27] == 0 &&
        !((D_8009A169 >> ((s8)v - 1)) & 1)) {
        func_800EEB30_ovl24();
    }
    a0[1] = 5;
    a0[2] = 0;
}
