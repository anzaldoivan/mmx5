#include "types.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001CA0C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

M2C_UNK TestEvent(s32);
extern s32 D_800E81B8;
extern s32 D_800E81BC;
extern s32 D_800E81C0;
extern s32 D_800E81C4;

void func_8001DF18(void) {
    TestEvent(D_800E81B8);
    TestEvent(D_800E81BC);
    TestEvent(D_800E81C0);
    TestEvent(D_800E81C4);
}
#undef M2C_UNK

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001CA64.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

M2C_UNK TestEvent(s32);
extern s32 D_800E81C8;
extern s32 D_800E81CC;
extern s32 D_800E81D0;

void func_8001DF70(void) {
    TestEvent(D_800E81C8);
    TestEvent(D_800E81CC);
    TestEvent(D_800E81D0);
}
#undef M2C_UNK

s32 TestEvent(s32);
extern s32 D_800E81C8;
extern s32 D_800E81CC;
extern s32 D_800E81D0;

s32 func_8001DFB8(void) {
    s32 i = 0x3D08F;

    do {
        if (TestEvent(D_800E81C8)) {
            return 0;
        }
        if (TestEvent(D_800E81CC)) {
            return 1;
        }
        if (TestEvent(D_800E81D0)) {
            return 2;
        }
    } while (--i);
    return 3;
}
