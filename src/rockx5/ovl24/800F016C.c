#include "types.h"
#include "mmx5/globals.h"

extern s8 D_8009A424;
extern u16 D_800F4E60_ovl24[];
extern u16 D_800F5F74_ovl24;
extern s16 D_800F5F76_ovl24;

void func_800F016C_ovl24(u8* self) {
    s8 i = D_8009A424;

    if (i == 0) {
        D_800F5F76_ovl24 = 0;
        D_800F5F74_ovl24 = D_800F4E60_ovl24[i >> 31];
        self[2]++;
    }
}

void func_800F01C0_ovl24(u8* a0) {
    u8* p;

    if (D_800C9320.h & 0x8FF) {
        p = g_playthrough_state.u;
        if ((u32)(p[0x26] - 1) < 8) {
            p[0x28] = 0x7F;
            a0[1] = 2;
        } else {
            p[0x28] = 0x7F;
            a0[1] = 3;
        }
        a0[2] = 0;
    }
}
