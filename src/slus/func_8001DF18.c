/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001CA0C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK TestEvent(s32); /* extern */
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
