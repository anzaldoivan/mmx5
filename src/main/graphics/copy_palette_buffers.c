/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80017CD8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "addr.h"

#define SPAD28 (*(s32*)&D_1F800028)

void copy_palette_buffers(void) {
    __builtin_memcpy(D_8009A790.h, (void*)SPAD28, 0x4000);
    __builtin_memcpy(D_800A11A0.h, (void*)SPAD28, 0x4000);
}
