/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001C824.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/memcard.c:func_8001CEDC, AGPL-3.0; proven shared with X6 by exact signature a1a1bb6682a3 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32
M2C_UNK TestEvent(s32);
extern s32 D_800E81B8;
extern s32 D_800E81BC;
extern s32 D_800E81C0;
extern s32 D_800E81C4;

s32 func_8001DA18(void) {
    const long MAX_LOOPS = 250000;
    long var_s0;

    for (var_s0 = MAX_LOOPS - 1; var_s0 != 0; var_s0--) {
        if (TestEvent(D_800E81B8)) {
            return 0;
        }
        if (TestEvent(D_800E81BC)) {
            return 1;
        }
        if (TestEvent(D_800E81C0)) {
            return 2;
        }
        if (TestEvent(D_800E81C4)) {
            return 3;
        }
    }
    return 3;
}
