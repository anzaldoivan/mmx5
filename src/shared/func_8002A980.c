/* Shared body (DK-5), from the banked draft of func_8002A980 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @a8f96d1 src/shared/mugshot/func_800297F8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
extern s16 D_8009A206;
#define M2C_UNK s32

M2C_UNK DEDUP_NAME(s16* arg0) {
    s32 f = (u16)arg0[0x21];
    arg0[7] = (D_8009A206 >> 1) + f;
}
