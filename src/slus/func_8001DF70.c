/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001CA64.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK TestEvent(s32); /* extern */
extern s32 D_800E81C8;
extern s32 D_800E81CC;
extern s32 D_800E81D0;

void func_8001DF70(void) {
    TestEvent(D_800E81C8);
    TestEvent(D_800E81CC);
    TestEvent(D_800E81D0);
}
