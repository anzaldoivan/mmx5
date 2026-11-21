/* Adapted from mmx6 @a8f96d1 src/shared/mugshot/func_800297D8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern u16 D_8009A202;

void func_8002A960(u8* arg0) {
    s32 t = (s16)D_8009A202 >> 1;
    t += *(u16*)(arg0 + 0x40);
    *(s16*)(arg0 + 0xA) = t;
}
