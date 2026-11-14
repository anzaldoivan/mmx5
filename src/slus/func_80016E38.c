/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/800175F0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
s32 SpuGetKeyStatus(s32);

extern u8* D_8009A778;

s32 func_80016E38(u8 arg0) {
    u8* p = D_8009A778 + arg0 * 4;
    return SpuGetKeyStatus(1 << (p[3] & 0x1F)) == 0;
}
