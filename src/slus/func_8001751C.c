/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80017CD8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"

extern u16 D_8009A790[];
extern u16 D_800A11A0[];

#define SPAD28 (*(s32*)&D_1F800028)

void func_8001751C(void) {
    __builtin_memcpy(D_8009A790, (void*)SPAD28, 0x4000);
    __builtin_memcpy(D_800A11A0, (void*)SPAD28, 0x4000);
}
