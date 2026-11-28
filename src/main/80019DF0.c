#include "types.h"
#include "mmx5/globals.h"

#define D_800D1C00_as_D1C00_80019DF0 (*(D1C00_80019DF0*)&g_playthrough_state)

void func_80019DF0(u8* a0) {
    s32 idx = (s8)(((s8*)a0)[2] / 3);
    s32 v = D_800D1C00_as_D1C00_80019DF0.f1B8[idx];

    if (idx != 0) {
        v = -v;
    }
    if (v < 0) {
        a0[0x47] = 14;
        a0[3] = 1;
    } else {
        a0[3] = 0;
    }
}
#undef D_800D1C00_as_D1C00_80019DF0

#define D_800D1C00_as_D1C00_80019DF0 (*(D1C00_80019DF0*)&g_playthrough_state)

void func_80019E58(s8* p) {
    s32 idx = (s8)(p[2] / 3);
    s32 v = D_800D1C00_as_D1C00_80019DF0.f1B8[idx];

    if (((v < 0) ? -v : v) >= 10) {
        p[0x47] = 3;
        p[3] = 1;
    } else {
        p[3] = 0;
    }
}
#undef D_800D1C00_as_D1C00_80019DF0

/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/80018774.c, AGPL-3.0 (THIRD_PARTY.md). */
// clang-format off

#define D_800D1C00_as_X4_EngineObj (*(struct X4_EngineObj*)&g_playthrough_state)

void func_80019ECC(u8* arg0) {
    s32 v;
    s8 i;
    s8* p;

    i = (s8)arg0[2] / 3;
    p = (s8*)&D_800D1C00_as_X4_EngineObj;
    v = __builtin_abs((p - -i)[0x1B8]);
    arg0[3] = 1;
    arg0[0x47] = (v % 10) + 2;
}

void func_80019F54(u8* a0) {
    a0[3] = 1;
}
