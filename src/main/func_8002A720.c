/* Adapted from mmx6 @a8f96d1 refs/mmx6/src/SLUS_013.95/80026028.c:func_80029598, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

void func_8002A720(u8* arg0) {
    s16 delta;

    delta = (D_8009A0AA - *(s16*)(arg0 + 0xA)) - *(s16*)(arg0 + 0x30);
    if (delta < 0) {
        *(s16*)(arg0 + 0xA) = delta + *(s16*)(arg0 + 0xA);
        return;
    }
    delta = (D_8009A0AA - *(s16*)(arg0 + 0xA)) - *(s16*)(arg0 + 0x32);
    if (delta > 0) {
        *(s16*)(arg0 + 0xA) = delta + *(s16*)(arg0 + 0xA);
    }
}
