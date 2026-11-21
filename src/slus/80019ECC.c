#include "types.h"

/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/80018774.c, AGPL-3.0 (THIRD_PARTY.md). */
// clang-format off

extern struct X4_EngineObj D_800D1C00;

void func_80019ECC(u8* arg0) {
    s32 v;
    s8 i;
    s8* p;

    i = (s8)arg0[2] / 3;
    p = (s8*)&D_800D1C00;
    v = __builtin_abs((p - -i)[0x1B8]);
    arg0[3] = 1;
    arg0[0x47] = (v % 10) + 2;
}

void func_80019F54(u8* a0) {
    a0[3] = 1;
}
